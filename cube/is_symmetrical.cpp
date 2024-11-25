/*
import obj
get vertices, edges, faces from obj file
add a plane using 3 points
group vertices into two groups

method A:
1. confirm both sides have the same number of vertices
2. for loop to group 1, pair with the closest vertex in group 2, find distance

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
#include <map>
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

#include "sdl_test.h"


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
            m_left_v.reserve(reserveSize);
            m_right_v.reserve(reserveSize);
            m_boundingBox.push_back(Point(0,0,0));
            m_boundingBox.push_back(Point(0,0,0));
        }
        ~Mesh(){}

        std::vector<Point> m_vertices; // std is the standard library. it comes with c++. a vector of what? a vector of Point
        std::vector<Point> m_left_v;
        std::vector<Point> m_right_v;
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

            normal.m_x = u2 * v3 - u3 * v2;
            normal.m_y = u3 * v1 - u1 * v3;
            normal.m_z = u1 * v2 - u2 * v1;
        }
};

class Cell{
    public:
        Cell(Point& origin) : m_origin(origin), taken(false), paired(false) {}
        ~Cell(){}
        Point m_origin;
        bool taken;
        bool paired;
};

std::map<std::string, Cell> createCellMap(const Point& min, const Point& max, const float& dx, const float& dy, const float& dz) {
    std::map<std::string, Cell> cellMap;
    int numX = static_cast<int>(std::ceil((max.m_x - min.m_x) / dx));
    int numY = static_cast<int>(std::ceil((max.m_y - min.m_y) / dy));
    int numZ = static_cast<int>(std::ceil((max.m_z - min.m_z) / dz));

    std::cout << "\nIncrement in x: " << dx << std::endl;
    std::cout << "Increment in y: " << dy << std::endl;
    std::cout << "Increment in z: " << dz << std::endl;

    std::cout << "\nNumber of cells in x: " << numX << std::endl;
    std::cout << "Number of cells in y: " << numY << std::endl;
    std::cout << "Number of cells in z: " << numZ << std::endl;

    for (int i = 0; i < numX; i++) {
        for (int j = 0; j < numY; j++) {
            for (int k = 0; k < numZ; k++) {
                Point origin(min.m_x + i * dx, min.m_y + j * dy, min.m_z + k * dz);
                Cell cell(origin);
                cellMap.emplace(std::to_string(i) + "_" + std::to_string(j) + "_" + std::to_string(k), cell);
            }
        }
    }           
    return cellMap;
}


std::vector<int> pointToIndex(const Point& p, const Point& min, const float& dx, const float& dy, const float& dz) {
    std::vector<int> index(3);
    index[0] = static_cast<int>(std::floor((p.m_x - min.m_x) / dx));
    index[1] = static_cast<int>(std::floor((p.m_y - min.m_y) / dy));
    index[2] = static_cast<int>(std::floor((p.m_z - min.m_z) / dz));
    return index;
}

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

void loadOBJ(const std::string& filename, Mesh& mesh) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            Point p(x, y, z);
            mesh.addPoint(p);
        } 
    }
    file.close();
}

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

Point centroid(const Mesh& mesh) {
    float x = 0;
    float y = 0;
    float z = 0;
    for (int i = 0; i < mesh.m_vertices.size(); i++) {
        x += mesh.m_vertices[i].m_x;
        y += mesh.m_vertices[i].m_y;
        z += mesh.m_vertices[i].m_z;
    }
    x /= mesh.m_vertices.size();
    y /= mesh.m_vertices.size();
    z /= mesh.m_vertices.size();
    return Point(x, y, z);
}

Point mirroredPoint(const Point& p, const Plane& plane) {
    float normal_length = sqrt(plane.m_normal.m_x * plane.m_normal.m_x +
                                plane.m_normal.m_y * plane.m_normal.m_y +
                                plane.m_normal.m_z * plane.m_normal.m_z);
    
    Point normalized_normal(plane.m_normal.m_x / normal_length,
                            plane.m_normal.m_y / normal_length,
                            plane.m_normal.m_z / normal_length);
    float d = (p.m_x - plane.m_points[0].m_x) * normalized_normal.m_x +
              (p.m_y - plane.m_points[0].m_y) * normalized_normal.m_y +
              (p.m_z - plane.m_points[0].m_z) * normalized_normal.m_z;
    Point mirrored_p(p.m_x - 2 * d * normalized_normal.m_x,
                     p.m_y - 2 * d * normalized_normal.m_y,
                     p.m_z - 2 * d * normalized_normal.m_z);
    return mirrored_p;
}


int main() {
    std::string filename = "../../assembly_planner/models/indoor_plant_02.obj";
    Mesh mesh(100000);
    loadOBJ(filename, mesh);
    std::cout <<"Number of vertices in mesh: " << mesh.m_vertices.size() << std::endl;

    calculateBoundingBox(mesh);
    std::cout << "\nBounding box: " << mesh.m_boundingBox[0].m_x << ", " << mesh.m_boundingBox[0].m_y << ", " << mesh.m_boundingBox[0].m_z << std::endl;
    std::cout << "Bounding box: " << mesh.m_boundingBox[1].m_x << ", " << mesh.m_boundingBox[1].m_y << ", " << mesh.m_boundingBox[1].m_z << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();

    Point p1(0, 0, 0);
    Point p2(2, 0, 0);
    Point p3(0, 2, 0);
    Plane plane(p1, p2, p3);
    std::cout << "\nNormal of plane: " << plane.m_normal.m_x << ", " << plane.m_normal.m_y << ", " << plane.m_normal.m_z << std::endl;

    Point boundingBox_mirrored1 = mirroredPoint(mesh.m_boundingBox[0], plane);
    Point boundingBox_mirrored2 = mirroredPoint(mesh.m_boundingBox[1], plane);

    Point fullBoundingBox1(std::min(std::min(mesh.m_boundingBox[0].m_x, boundingBox_mirrored1.m_x), boundingBox_mirrored2.m_x),
                           std::min(std::min(mesh.m_boundingBox[0].m_y, boundingBox_mirrored1.m_y), boundingBox_mirrored2.m_y),
                           std::min(std::min(mesh.m_boundingBox[0].m_z, boundingBox_mirrored1.m_z), boundingBox_mirrored2.m_z));
    Point fullBoundingBox2(std::max(std::max(mesh.m_boundingBox[1].m_x, boundingBox_mirrored1.m_x), boundingBox_mirrored2.m_x),
                            std::max(std::max(mesh.m_boundingBox[1].m_y, boundingBox_mirrored1.m_y), boundingBox_mirrored2.m_y),
                            std::max(std::max(mesh.m_boundingBox[1].m_z, boundingBox_mirrored1.m_z), boundingBox_mirrored2.m_z)); 
    
    std::cout << "\nFull bounding box: " << fullBoundingBox1.m_x << ", " << fullBoundingBox1.m_y << ", " << fullBoundingBox1.m_z << std::endl;
    std::cout << "Full bounding box: " << fullBoundingBox2.m_x << ", " << fullBoundingBox2.m_y << ", " << fullBoundingBox2.m_z << std::endl;

    float dx = 0.1;
    float dy = 0.1;
    float dz = 0.1;

    std::map<std::string, Cell> cellMap = createCellMap(fullBoundingBox1, fullBoundingBox2, dx, dy, dz);
    std::cout << "\nNumber of cells: " << cellMap.size() << std::endl;

    Mesh outMesh1(100000);
    Mesh outMesh2(100000);
    splitMesh(plane, mesh, outMesh1, outMesh2);
    std::cout << "\nNumber of vertices in outMesh1: " << outMesh1.m_vertices.size() << std::endl;
    std::cout << "Number of vertices in outMesh2: " << outMesh2.m_vertices.size() << std::endl;
        
    for (int i = 0; i < outMesh1.m_vertices.size(); i++){
        std::vector<int> index = pointToIndex(outMesh1.m_vertices[i], fullBoundingBox1, dx, dy, dz);
        auto it = cellMap.find(std::to_string(index[0]) + "_" + std::to_string(index[1]) + "_" + std::to_string(index[2]));
        if (it != cellMap.end()) {
            if (it->second.paired == true) {
                continue;
            } else {
                it->second.taken = true;
                Point mirrored_p = mirroredPoint(outMesh1.m_vertices[i], plane);
                std::vector<int> index_mirrored = pointToIndex(mirrored_p, fullBoundingBox1, dx, dy, dz);
                auto it_mirrored = cellMap.find(std::to_string(index_mirrored[0]) + "_" + std::to_string(index_mirrored[1]) + "_" + std::to_string(index_mirrored[2]));
                if (it_mirrored != cellMap.end()) {
                    if (it_mirrored->second.taken == true) {
                        it->second.paired = true;
                        it_mirrored->second.paired = true;
                    }
                } else {
                    std::cout << "Mirrored cell not found." << std::endl;
                }
            }
        } else {
            std::cout << "\nMesh 1" << std::endl;
            std::cout << "Point: " << outMesh1.m_vertices[i].m_x << ", " << outMesh1.m_vertices[i].m_y << ", " << outMesh1.m_vertices[i].m_z << std::endl;
            std::cout << "Index: " << index[0] << ", " << index[1] << ", " << index[2] << std::endl;
            std::cout << "Cell not found." << std::endl;
        }
    }

    for (int i = 0; i < outMesh2.m_vertices.size(); i++){
        std::vector<int> index = pointToIndex(outMesh2.m_vertices[i], fullBoundingBox1, dx, dy, dz);
        auto it = cellMap.find(std::to_string(index[0]) + "_" + std::to_string(index[1]) + "_" + std::to_string(index[2]));
        if (it != cellMap.end()) {
            if (it->second.paired == true) {
                continue;
            } else {
                it->second.taken = true;
                Point mirrored_p = mirroredPoint(outMesh2.m_vertices[i], plane);
                std::vector<int> index_mirrored = pointToIndex(mirrored_p, fullBoundingBox1, dx, dy, dz);
                auto it_mirrored = cellMap.find(std::to_string(index_mirrored[0]) + "_" + std::to_string(index_mirrored[1]) + "_" + std::to_string(index_mirrored[2]));
                if (it_mirrored != cellMap.end()) {
                    if (it_mirrored->second.taken == true) {
                        it->second.paired = true;
                        it_mirrored->second.paired = true;
                    }
                } else {
                    std::cout << "Mirrored cell not found." << std::endl;
                }
            }
        } else {
            std::cout << "\nMesh 2" << std::endl;
            std::cout << "Point: " << outMesh2.m_vertices[i].m_x << ", " << outMesh2.m_vertices[i].m_y << ", " << outMesh2.m_vertices[i].m_z << std::endl;
            std::cout << "Index: " << index[0] << ", " << index[1] << ", " << index[2] << std::endl;
            std::cout << "Cell not found." << std::endl;
        }
    }

    int numTaken = 0;
    int numPaired = 0;
    for (const auto& pair : cellMap) {
        if (pair.second.taken == true) {
            numTaken++;
        }
        if (pair.second.paired == true) {
            numPaired++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "\nNumber of cells taken: " << numTaken << std::endl;
    std::cout << "Number of cells paired: " << numPaired << std::endl;

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "\nElapsed time: " << elapsed.count() << " s" << std::endl;


    // Visualization demo
    std::vector<Vertex> vertices = {
        {{0.0f,  0.5f, 1.0f}, {1.0f, 0.0f, 0.0f}}, // Top vertex (red)
        {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f, 0.0f}}, // Bottom right vertex (green)
        {{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f, 1.0f}}  // Bottom left vertex (blue)
    };

    std::vector<GLuint> indices = {0, 1, 2}; // Triangle: Vertex 0, Vertex 1, Vertex 2
    visualize_mesh(vertices, indices);
    
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
