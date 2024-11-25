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
1. subdivide both sides into 64 cubes
2. calculate the centroids of the points in each cube
3. map the distances between the centroids of their counterparts on the other side
4. add up the distances
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


class Point{
    public:
        Point() = default;
        Point(float x, float y, float z){
            m_x = x; // an assignment, an operation. like a verb
            m_y = y;
            m_z = z;
        }
        ~Point(){}
        float m_x = 0.0; // a declaration describes structure for the data. like a noun
        float m_y = 0.0;
        float m_z = 0.0;
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

class Cube{
    public:
        Cube(Point& origin, float& x, float& y, float& z) : m_origin(origin) {
            m_origin = origin;
            m_x = x;
            m_y = y;
            m_z = z;
        }
        ~Cube(){}
        Point m_origin;
        float m_x;
        float m_y;
        float m_z;
};

//std::vector<std::vector<std::vector<int> > > create3DArray(const Mesh& mesh) {
//    int x_size = static_cast<int>(mesh.m_boundingBox[1].m_x - mesh.m_boundingBox[0].m_x) + 1;
 //   int y_size = static_cast<int>(mesh.m_boundingBox[1].m_y - mesh.m_boundingBox[0].m_y) + 1;
 //   int z_size = static_cast<int>(mesh.m_boundingBox[1].m_z - mesh.m_boundingBox[0].m_z) + 1;

   // std::vector<std::vector<std::vector<int>>> array3D(x_size, std::vector<std::vector<int>>(y_size, std::vector<int>(z_size, 0)));
    //return array3D;
//}

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
    float d = ((p.m_x - plane.m_points[0].m_x) * plane.m_normal.m_x +
              (p.m_y - plane.m_points[0].m_y) * plane.m_normal.m_y +
              (p.m_z - plane.m_points[0].m_z) * plane.m_normal.m_z) / normal_length;
    Point mirrored_p(p.m_x - 2 * d * plane.m_normal.m_x,
                     p.m_y - 2 * d * plane.m_normal.m_y,
                     p.m_z - 2 * d * plane.m_normal.m_z);
    return mirrored_p;
}


int main() {
    std::string filename = "../../assembly_planner/models/indoor_plant_02.obj";
    Mesh mesh(100000);
    loadOBJ(filename, mesh);
    std::cout <<"Number of vertices in mesh: " << mesh.m_vertices.size() << std::endl;

    calculateBoundingBox(mesh);
    std::cout << "Bounding box: " << mesh.m_boundingBox[0].m_x << ", " << mesh.m_boundingBox[0].m_y << ", " << mesh.m_boundingBox[0].m_z << std::endl;

    Point center = centroid(mesh);
    std::cout << "Center of mesh: " << center.m_x << ", " << center.m_y << ", " << center.m_z << std::endl;
    
    Point p1(0, 0, 0);
    Point p2(2, 0, 0);
    Point p3(0, 2, 0);
    Plane plane(p1, p2, p3);
    std::cout << "Normal of plane: " << plane.m_normal.m_x << ", " << plane.m_normal.m_y << ", " << plane.m_normal.m_z << std::endl;

    Mesh outMesh1(100000);
    Mesh outMesh2(100000);
    splitMesh(plane, mesh, outMesh1, outMesh2);
    std::cout << "Number of vertices in outMesh1: " << outMesh1.m_vertices.size() << std::endl;
    std::cout << "Number of vertices in outMesh2: " << outMesh2.m_vertices.size() << std::endl;

    Point center1 = centroid(outMesh1);
    Point center2 = centroid(outMesh2);
    std::cout << "Center of outMesh1: " << center1.m_x << ", " << center1.m_y << ", " << center1.m_z << std::endl;
    std::cout << "Center of outMesh2: " << center2.m_x << ", " << center2.m_y << ", " << center2.m_z << std::endl;

    
    std::vector<Point> grid;
    // createSymmetricalGrid(plane, mesh, grid, 10);
   // std::cout << "Number of points in grid: " << grid.size() << std::endl;

    //std::vector<std::vector<std::vector<int>>> array3D = create3DArray(mesh);
    //std::cout << "Size of 3D array: " << array3D.size() << ", " << array3D[0].size() << ", " << array3D[0][0].size() << std::endl;

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
