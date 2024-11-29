/*
import obj
get vertices, edges, faces from obj file
add a plane using 3 points
group vertices into two groups

method A:
1. confirm both sides have the same number of vertices (or not)
2. for loop to group 1, pair with the closest vertex in group 2, find distance. Use spatial data structure (kd tree bsp tree etc)

method B:
0. fill the holes to make both meshes solid
1. mirror mesh 1 along cutting plane
2. boolean subtract mesh 2 from mirrored mesh 1
3. calculate left over volume
4. the smaller the volume, the more symmetrical the mesh is

method C:
1. subdivide both sides into 64 Cells
2. calculate the centroids of the points in each cell
3. map the distances between the centroids of their counterparts on the other side
4. add up the distances
*/

#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <assert.h>

#include "sdl_test.h"

class Cell {
public:
    bool m_taken = false;
    bool m_paired = false;
};

class CellGrid {
public:
    CellGrid(int x, int y, int z) {
        m_x = x;
        m_y = y;
        m_z = z;
        m_cells = new Cell[x * y * z];
    }
    ~CellGrid() {
        delete[] m_cells;
    }

    void set(int x, int y, int z, const Cell& cell) { // set a cell
        assert(x >= 0 && x < m_x);
        assert(y >= 0 && y < m_y);
        assert(z >= 0 && z < m_z);
        m_cells[z * m_x * m_y + y * m_x + x] = cell;
    }

    Cell* get(int x, int y, int z) { // return a pointer to a cell
        if (x < 0 || x >= m_x) return nullptr;
        if (y < 0 || y >= m_y) return nullptr;
        if (z < 0 || z >= m_z) return nullptr;
        return &(m_cells[z * m_x * m_y + y * m_x + x]);
    }

    void reset() {
        memset(m_cells, 0, m_x * m_y * m_z * sizeof(Cell));
    }

    void getDimensions(int& x, int& y, int& z) {
        x = m_x;
        y = m_y;
        z = m_z;
    }

    int size() {
        return m_x * m_y * m_z;
    }

private:
    Cell* m_cells = nullptr;
    int m_x = 0;
    int m_y = 0;
    int m_z = 0;
};


class Point{
    public:
        Point(float x, float y, float z){
            m_x = x; // an assignment, an operation. like a verb
            m_y = y;
            m_z = z;
        }
        ~Point(){}
        float m_x; // a declaration describes structure for the data. like a noun
        float m_y;
        float m_z;
};

// A vector of what? A vector of point.
// Like a verb, like a noun
// Like the wind, like the rain
// Like a verb, like a noun
// Like a bird that flies, like a bird that sings
// A vector of what? A vector of point.

class Mesh{
    public:
        Mesh(int reserveSize) { //constructor
            m_vertices.reserve(reserveSize);
            m_faces.reserve(reserveSize*3);
            m_boundingBox.push_back(Point(0,0,0));
            m_boundingBox.push_back(Point(0,0,0));
        }
        ~Mesh(){}

        std::vector<Point> m_vertices; // std is the standard library. it comes with c++. a vector of what? a vector of Point
        std::vector<std::vector<int>> m_faces;
        std::vector<Point> m_boundingBox;

        void addPoint(Point &p){
            m_vertices.push_back(p);
        }
};

class Plane{ //
    public:
        Plane(Point& p1, Point& p2, Point& p3) : m_normal(0, 0, 0) { //why does m_normal need to be initialized here?
            m_points.push_back(p1);
            m_points.push_back(p2);
            m_points.push_back(p3);
            calculateNormal(m_points[0], m_points[1], m_points[2], m_normal);    
        }
        ~Plane() {}

        std::vector<Point> m_points;
        Point m_normal;

        void calculateNormal(Point& p1, Point& p2, Point& p3, Point& normal) {
            float u1 = p2.m_x - p1.m_x;
            float u2 = p2.m_y - p1.m_y;
            float u3 = p2.m_z - p1.m_z;

            float v1 = p3.m_x - p1.m_x;
            float v2 = p3.m_y - p1.m_y;
            float v3 = p3.m_z - p1.m_z;

            float w_x = u2 * v3 - u3 * v2;
            float w_y = u3 * v1 - u1 * v3;
            float w_z = u1 * v2 - u2 * v1;

            float w_length = sqrt(w_x * w_x + w_y * w_y + w_z * w_z);
            
            normal.m_x = w_x / w_length;
            normal.m_y = w_y / w_length;
            normal.m_z = w_z / w_length;
        }
};

void pointToIndex(const Point& p, const Point& min, const float& dx, const float& dy, const float& dz, int& x, int& y, int& z) {
    x = static_cast<int>(std::floor((p.m_x - min.m_x) / dx));
    y = static_cast<int>(std::floor((p.m_y - min.m_y) / dy));
    z = static_cast<int>(std::floor((p.m_z - min.m_z) / dz));
}

void loadOBJ(const std::string& filename, Mesh& mesh) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    float x_min = std::numeric_limits<float>::max();
    float y_min = std::numeric_limits<float>::max();
    float z_min = std::numeric_limits<float>::max();
    float x_max = std::numeric_limits<float>::min();
    float y_max = std::numeric_limits<float>::min();
    float z_max = std::numeric_limits<float>::min();

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            if (x < x_min) x_min = x;
            if (y < y_min) y_min = y;
            if (z < z_min) z_min = z;
            if (x > x_max) x_max = x;
            if (y > y_max) y_max = y;
            if (z > z_max) z_max = z;
            Point p(x, y, z);
            mesh.addPoint(p);
        } else if (prefix == "f") {
            std::vector<int> face;
            std::string vertex;
            while (iss >> vertex) {
                std::istringstream viss(vertex);
                int index;
                viss >> index;
                face.push_back(index - 1); // OBJ format uses 1-based indexing
            }
            mesh.m_faces.push_back(face);
        }
    }
    mesh.m_boundingBox[0].m_x = x_min;
    mesh.m_boundingBox[0].m_y = y_min;
    mesh.m_boundingBox[0].m_z = z_min;
    mesh.m_boundingBox[1].m_x = x_max;
    mesh.m_boundingBox[1].m_y = y_max;
    mesh.m_boundingBox[1].m_z = z_max;
    file.close();
}

void exportOBJ(const std::string &filename, const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices, const Plane &mirrorPlane) {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Write vertices
    for (const auto &vertex : vertices) {
        file << "v " << vertex.position[0] << " " << vertex.position[1] << " " << vertex.position[2] << " " << vertex.color[0] << " " << vertex.color[1] << " " << vertex.color[2] << std::endl;
    }

    // Write faces
    for (size_t i = 0; i < indices.size(); i += 3) {
        file << "f " << indices[i] + 1 << " " << indices[i + 1] + 1 << " " << indices[i + 2] + 1 << std::endl;
    }

    // Write mirror plane
    file << "v " << mirrorPlane.m_points[0].m_x << " " << mirrorPlane.m_points[0].m_y << " " << mirrorPlane.m_points[0].m_z << std::endl;
    file << "v " << mirrorPlane.m_points[1].m_x << " " << mirrorPlane.m_points[1].m_y << " " << mirrorPlane.m_points[1].m_z << std::endl;
    file << "v " << mirrorPlane.m_points[2].m_x << " " << mirrorPlane.m_points[2].m_y << " " << mirrorPlane.m_points[2].m_z << std::endl;
    file << "f " << vertices.size() + 1 << " " << vertices.size() + 2 << " " << vertices.size() + 3 << std::endl;

    file.close();
    std::cout << "Exported mesh to " << filename << std::endl;
}

/* //Not used
void calculateBoundingBox(Mesh& mesh) {
    mesh.m_boundingBox[0].m_x = mesh.m_vertices[0].m_x;
    mesh.m_boundingBox[0].m_y = mesh.m_vertices[0].m_y;
    mesh.m_boundingBox[0].m_z = mesh.m_vertices[0].m_z;

    mesh.m_boundingBox[1].m_x = mesh.m_vertices[0].m_x;
    mesh.m_boundingBox[1].m_y = mesh.m_vertices[0].m_y;
    mesh.m_boundingBox[1].m_z = mesh.m_vertices[0].m_z;

    for (int i = 1; i < mesh.m_vertices.size(); i++) {
        if (mesh.m_vertices[i].m_x < mesh.m_boundingBox[0].m_x) {
            mesh.m_boundingBox[0].m_x = mesh.m_vertices[i].m_x;
        }
        if (mesh.m_vertices[i].m_y < mesh.m_boundingBox[0].m_y) {
            mesh.m_boundingBox[0].m_y = mesh.m_vertices[i].m_y;
        }
        if (mesh.m_vertices[i].m_z < mesh.m_boundingBox[0].m_z) {
            mesh.m_boundingBox[0].m_z = mesh.m_vertices[i].m_z;
        }

        if (mesh.m_vertices[i].m_x > mesh.m_boundingBox[1].m_x) {
            mesh.m_boundingBox[1].m_x = mesh.m_vertices[i].m_x;
        }
        if (mesh.m_vertices[i].m_y > mesh.m_boundingBox[1].m_y) {
            mesh.m_boundingBox[1].m_y = mesh.m_vertices[i].m_y;
        }
        if (mesh.m_vertices[i].m_z > mesh.m_boundingBox[1].m_z) {
            mesh.m_boundingBox[1].m_z = mesh.m_vertices[i].m_z;
        }
    }
}
*/

void mirroredPoint(const Point& p, const Plane& plane, Point& mirrored_p) {
    float d = (p.m_x - plane.m_points[0].m_x) * plane.m_normal.m_x +
              (p.m_y - plane.m_points[0].m_y) * plane.m_normal.m_y +
              (p.m_z - plane.m_points[0].m_z) * plane.m_normal.m_z;
    mirrored_p.m_x = p.m_x - 2 * d * plane.m_normal.m_x;
    mirrored_p.m_y = p.m_y - 2 * d * plane.m_normal.m_y;
    mirrored_p.m_z = p.m_z - 2 * d * plane.m_normal.m_z;
}

std::shared_ptr<CellGrid> createCellGrid(const Point& min, const Point& max, const float& dx, const float& dy, const float& dz) {
    std::shared_ptr<CellGrid> cg = std::make_shared<CellGrid>(static_cast<int>(std::ceil((max.m_x - min.m_x) / dx)),
                      static_cast<int>(std::ceil((max.m_y - min.m_y) / dy)),
                      static_cast<int>(std::ceil((max.m_z - min.m_z) / dz)));
    return cg;
}
// shared_ptr is slightly slightly slightly less efficient than a pointer, automatically deletes memory when it goes out of scope

/* //Not used
void splitMesh(const Plane& plane, const Mesh& inMesh, Mesh& outMesh1, Mesh& outMesh2) {
    for (int i = 0; i < inMesh.m_vertices.size(); i++) {
        Point p = inMesh.m_vertices[i];
        float d = (p.m_x - plane.m_points[0].m_x) * plane.m_normal.m_x +
                  (p.m_y - plane.m_points[0].m_y) * plane.m_normal.m_y +
                  (p.m_z - plane.m_points[0].m_z) * plane.m_normal.m_z;
        if (d > 0) {
            outMesh1.m_vertices.push_back(p);
        } else {
            outMesh2.m_vertices.push_back(p);
        }
    }
}
*/

void symmetryMappingGrid(const Plane& plane, const Mesh& mesh, std::shared_ptr<CellGrid>& cellGrid, const float dx, const float dy, const float dz, int& numTaken, int& numPaired, float& symmetryScore) {
    for (int i = 0; i < mesh.m_vertices.size(); i++) {
        int x = 0;
        int y = 0;
        int z = 0;
        pointToIndex(mesh.m_vertices[i], mesh.m_boundingBox[0], dx, dy, dz, x, y, z); // based on bounding box
        Cell* cell = cellGrid->get(x, y, z);
        if (cell->m_taken == true) {
            continue;
        } else {
            cell->m_taken = true;
            numTaken++;
            Point mirrored_p(0,0,0);
            mirroredPoint(mesh.m_vertices[i], plane, mirrored_p);
            int mirrored_x = 0;
            int mirrored_y = 0;
            int mirrored_z = 0;
            pointToIndex(mirrored_p, mesh.m_boundingBox[0], dx, dy, dz, mirrored_x, mirrored_y, mirrored_z); // based on bounding box
            Cell* mirrored_cell = cellGrid->get(mirrored_x, mirrored_y, mirrored_z);
            if (mirrored_cell != nullptr) {
                if (mirrored_cell->m_taken == true) {
                    cell->m_paired = true;
                    numPaired++;
                    if (mirrored_cell->m_paired == false) {
                        mirrored_cell->m_paired = true;
                        numPaired++;
                    }
                }
            }
        }
    }
    symmetryScore = static_cast<float>(numPaired) / static_cast<float>(numTaken);
    std::cout << "Cells taken: " << numTaken << std::endl;
    std::cout << "Cells paired: " << numPaired << std::endl;
    std::cout << "Symmetry score: " << symmetryScore << std::endl;
}

void cleanUpCellGrid(const std::shared_ptr<CellGrid>& cellGrid, int& numTaken, int& numPaired, float& symmetryScore) {
    cellGrid->reset();
    numTaken = 0;
    numPaired = 0;
    symmetryScore = 0;
    std::cout << "\nCellGrid cleaned up." << std::endl;
}

int main() {
    auto total_start = std::chrono::high_resolution_clock::now();
    std::string filename = "../../assembly_planner/models/indoor_plant_02.obj";
    Mesh mesh(100000);
    loadOBJ(filename, mesh);
    std::cout <<"Number of vertices in mesh: " << mesh.m_vertices.size() << std::endl;
    std::cout <<"Number of faces in mesh: " << mesh.m_faces.size() << std::endl;

    auto step_0 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_step_0 = step_0 - total_start;
    std::cout << "Step 0 elapsed time: " << elapsed_step_0.count() << " s" << std::endl;

    std::cout << "\nBounding box: " << mesh.m_boundingBox[0].m_x << ", " << mesh.m_boundingBox[0].m_y << ", " << mesh.m_boundingBox[0].m_z << std::endl;
    std::cout << "Bounding box: " << mesh.m_boundingBox[1].m_x << ", " << mesh.m_boundingBox[1].m_y << ", " << mesh.m_boundingBox[1].m_z << std::endl;
    
    // Generate a plane
    Point p1(0, 0, 0);
    Point p2(2, 0, 0);
    Point p3(0, 2, 0);
    Plane plane(p1, p2, p3);
    std::cout << "\nNormal of plane: " << plane.m_normal.m_x << ", " << plane.m_normal.m_y << ", " << plane.m_normal.m_z << std::endl;

    // Create cell map
    float dx = 0.1;
    float dy = 0.1;
    float dz = 0.1;

    auto step_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_step_1 = step_1 - step_0;
    std::cout << "Step 1 elapsed time: " << elapsed_step_1.count() << " s" << std::endl;
    
    std::shared_ptr<CellGrid> cellGrid = createCellGrid(mesh.m_boundingBox[0], mesh.m_boundingBox[1], dx, dy, dz);
    //std::map<std::string, Cell> cellMap = createCellMap(mesh.m_boundingBox[0], mesh.m_boundingBox[1], dx, dy, dz); //Bounding box
    std::cout << "\nNumber of cells: " << cellGrid->size() << std::endl;

    auto step_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_step_2 = step_2 - step_1;
    std::cout << "Step 2 elapsed time: " << elapsed_step_2.count() << " s" << std::endl;

    // check symmetry
    int numTaken = 0;
    int numPaired = 0;
    float symmetryScore = 0;
    int outputNum = 0;

    // Visualization of the loaded mesh
    std::vector<Vertex> meshVertices;
    std::vector<GLuint> meshIndices;
    
    for (int i = 0; i < 5; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        // Randomly create a Plane
        float x1 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float y1 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float z1 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        Point p1(x1, y1, z1);

        float x2 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float y2 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float z2 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        Point p2(x2, y2, z2);

        float x3 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float y3 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float z3 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        Point p3(x3, y3, z3);

        std::cout << "\nPlane's 3 points: " << p1.m_x << ", " << p1.m_y << ", " << p1.m_z << std::endl;

        Plane mirrorPlane(p1, p2, p3);
        cleanUpCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
        symmetryMappingGrid(mirrorPlane, mesh, cellGrid, dx, dy, dz, numTaken, numPaired, symmetryScore);
        //evaluateSymmetryCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
        
        auto loop1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = loop1 - start;
        std::cout << "Symmetry mapping time: " << elapsed.count() << " s" << std::endl;

        meshVertices.clear();
        meshIndices.clear();
    
        for (int i = 0; i < mesh.m_vertices.size(); i++) {
            int x = 0;
            int y = 0;
            int z = 0;
            pointToIndex(mesh.m_vertices[i], mesh.m_boundingBox[0], dx, dy, dz, x, y, z);
            Cell* cell = cellGrid->get(x, y, z);
            if (cell != nullptr && cell->m_paired) {
                meshVertices.push_back({{mesh.m_vertices[i].m_x, mesh.m_vertices[i].m_y, mesh.m_vertices[i].m_z}, {0.0f, 1.0f, 0.0f}});
                //meshVertices[i].color[0] = 0.0f; // Green
                //meshVertices[i].color[1] = 1.0f;
                //meshVertices[i].color[2] = 0.0f;
            } else {
                meshVertices.push_back({{mesh.m_vertices[i].m_x, mesh.m_vertices[i].m_y, mesh.m_vertices[i].m_z}, {0.0f, 0.0f, 1.0f}});
                //meshVertices[i].color[0] = 0.0f; // Blue
                //meshVertices[i].color[1] = 0.0f;
                //meshVertices[i].color[2] = 1.0f;
            }
        }
        for (const auto& face : mesh.m_faces) {
            for (const auto& index : face) {
                meshIndices.push_back(index);
            }
        }
        //visualize_mesh(meshVertices, meshIndices);
        
        exportOBJ("output_" + std::to_string(outputNum) + ".obj", meshVertices, meshIndices, mirrorPlane);
        outputNum++;

        auto loop2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_loop = loop2 - loop1;
        std::cout << "Obj exporting time: " << elapsed_loop.count() << " s" << std::endl;
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    cleanUpCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
    symmetryMappingGrid(plane, mesh, cellGrid, dx, dy, dz, numTaken, numPaired, symmetryScore);
    //evaluateSymmetryCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s" << std::endl;

    /* 
    // Visualization demo
    std::vector<Vertex> vertices = {
        {{0.0f,  0.5f, 1.0f}, {1.0f, 0.0f, 0.0f}}, // Top vertex (red)
        {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}}, // Bottom right vertex (green)
        {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}}  // Bottom left vertex (blue)
    };

    std::vector<GLuint> indices = {0, 1, 2}; // Triangle: Vertex 0, Vertex 1, Vertex 2
    visualize_mesh(vertices, indices);
    */
   
    auto total_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> total_elapsed = total_end - total_start;
    std::cout << "\n\nTotal elapsed time: " << total_elapsed.count() << " s" << std::endl;


//    for (const auto& vertex : mesh.m_vertices) {
//        meshVertices.push_back({{vertex.m_x, vertex.m_y, vertex.m_z}, {1.0f, 1.0f, 1.0f}});
//    }


    meshVertices.clear();
    meshIndices.clear();

    for (int i = 0; i < mesh.m_vertices.size(); i++) {
        int x = 0;
        int y = 0;
        int z = 0;
        pointToIndex(mesh.m_vertices[i], mesh.m_boundingBox[0], dx, dy, dz, x, y, z);
        Cell* cell = cellGrid->get(x, y, z);
        if (cell != nullptr && cell->m_paired) {
            meshVertices.push_back({{mesh.m_vertices[i].m_x, mesh.m_vertices[i].m_y, mesh.m_vertices[i].m_z}, {0.0f, 1.0f, 0.0f}});
            //meshVertices[i].color[0] = 0.0f; // Green
            //meshVertices[i].color[1] = 1.0f;
            //meshVertices[i].color[2] = 0.0f;
        } else {
            meshVertices.push_back({{mesh.m_vertices[i].m_x, mesh.m_vertices[i].m_y, mesh.m_vertices[i].m_z}, {0.0f, 0.0f, 1.0f}});
            //meshVertices[i].color[0] = 0.0f; // Blue
            //meshVertices[i].color[1] = 0.0f;
            //meshVertices[i].color[2] = 1.0f;
        }
    }
    for (const auto& face : mesh.m_faces) {
        for (const auto& index : face) {
            meshIndices.push_back(index);
        }
    }

    //visualize_mesh(meshVertices, meshIndices);
    exportOBJ("output_x.obj", meshVertices, meshIndices, plane);
    
    return 0;
}


/*
(*m_points) = Point(x, y, z)
*(m_points + 1) = Point(x, y, z)
*(m_points + 2) = Point(x, y, z)
m_points[0] = Point(x, y, z)
m_points[1] = Point(x, y, z)
m_points[2] = Point(x, y, z)
*/
