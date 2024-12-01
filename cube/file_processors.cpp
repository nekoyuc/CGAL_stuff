#include "file_processors.h"
#include "sdl_test.h"

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
            std::vector<std::string> lineSegments;
            std::istringstream iss(line.substr(2));
            std::string segment;
            std::string vertex;
            
            while (iss >> segment) {
                lineSegments.push_back(segment);
            }

            for (const auto& segment : lineSegments) {
                size_t slashPos = segment.find('/');
                if (slashPos != std::string::npos) {
                    vertex = segment.substr(0, slashPos);
                    face.push_back(std::stoi(vertex) - 1); // OBJ indices start from 1
                }
            }

            mesh.m_faces.push_back(face);

        } else {
            continue;
        }
    }

    mesh.m_boundingBox[0].m_x = x_min;
    mesh.m_boundingBox[0].m_y = y_min;
    mesh.m_boundingBox[0].m_z = z_min;
    mesh.m_boundingBox[1].m_x = x_max;
    mesh.m_boundingBox[1].m_y = y_max;
    mesh.m_boundingBox[1].m_z = z_max;
    mesh.m_boundingCenter.m_x = (x_min + x_max) / 2;
    mesh.m_boundingCenter.m_y = (y_min + y_max) / 2;
    mesh.m_boundingCenter.m_z = (z_min + z_max) / 2;
    file.close();
}

void exportOBJ(const std::string &filename, const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices, const PlaneNormal &mirrorPlane) {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Write vertices
    for (const auto &vertex : vertices) {
        file << "v " << vertex.position[0] << " " << vertex.position[1] << " " << vertex.position[2] << " " << vertex.color[0] << " " << vertex.color[1] << " " << vertex.color[2] << std::endl;
    }

    // Write mirror plane
    Point u(0,0,0), v(0,0,0);
    if (std::abs(mirrorPlane.m_normal.m_x) > std::abs(mirrorPlane.m_normal.m_y)) {
        u = Point(-mirrorPlane.m_normal.m_z * 10, 0, mirrorPlane.m_normal.m_x * 10);
    } else {
        u = Point(0, mirrorPlane.m_normal.m_z * 10, -mirrorPlane.m_normal.m_y * 10);
    }
    v = Point(mirrorPlane.m_normal.m_y * u.m_z - mirrorPlane.m_normal.m_z * u.m_y,
              mirrorPlane.m_normal.m_z * u.m_x  - mirrorPlane.m_normal.m_x * u.m_z,
              mirrorPlane.m_normal.m_x * u.m_y - mirrorPlane.m_normal.m_y * u.m_x);
    file << "v " << mirrorPlane.m_coordinate.m_x << " " << mirrorPlane.m_coordinate.m_y << " " << mirrorPlane.m_coordinate.m_z << std::endl;
    file << "v " << mirrorPlane.m_coordinate.m_x + u.m_x << " " << mirrorPlane.m_coordinate.m_y + u.m_y << " " << mirrorPlane.m_coordinate.m_z + u.m_z << std::endl;
    file << "v " << mirrorPlane.m_coordinate.m_x + v.m_x << " " << mirrorPlane.m_coordinate.m_y + v.m_y << " " << mirrorPlane.m_coordinate.m_z + v.m_z << std::endl;

    // Write faces
    for (size_t i = 0; i < indices.size(); i += 4) {
        file << "f " << indices[i] + 1 << " " << indices[i + 1] + 1 << " " << indices[i + 2] + 1 << " " << indices[i + 3] + 1 << std::endl; // OBJ format uses 1-based indexing
    }
    file << "f " << vertices.size() + 1 << " " << vertices.size() + 2 << " " << vertices.size() + 3 << std::endl; // Indices for the mirror plane

    file.close();
}
