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
#include "cell.h"
#include "geometry.h"
#include "file_processors.h"
#include "operations.h"

int main() {
    auto total_start = std::chrono::high_resolution_clock::now();
    std::string filename = "../../assembly_planner/models/indoor_plant_02.obj";
    Mesh mesh(100000);
    loadOBJ(filename, mesh);
    std::cout <<"Number of vertices in mesh: " << mesh.m_vertices.size() << std::endl;
    std::cout <<"Number of faces in mesh: " << mesh.m_faces.size() << std::endl;

    auto step_0 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_step_0 = step_0 - total_start;
    std::cout << "Step 0 (importing mesh) elapsed time: " << elapsed_step_0.count() << " s" << std::endl;

    std::cout << "\nBounding box: " << mesh.m_boundingBox[0].m_x << ", " << mesh.m_boundingBox[0].m_y << ", " << mesh.m_boundingBox[0].m_z << std::endl;
    std::cout << "Bounding box: " << mesh.m_boundingBox[1].m_x << ", " << mesh.m_boundingBox[1].m_y << ", " << mesh.m_boundingBox[1].m_z << std::endl;
    
    // Create cell map
    float dx = 0.3;
    float dy = 0.3;
    float dz = 0.3;

    auto step_1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_step_1 = step_1 - step_0;
    std::cout << "Step 1 (calculating bounding box) elapsed time: " << elapsed_step_1.count() << " s" << std::endl;
    
    std::shared_ptr<CellGrid> cellGrid = createCellGrid(mesh.m_boundingBox[0], mesh.m_boundingBox[1], dx, dy, dz);
    std::cout << "\nNumber of cells: " << cellGrid->size() << std::endl;

    auto step_2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_step_2 = step_2 - step_1;
    std::cout << "Step 2 (creating cell grid) elapsed time: " << elapsed_step_2.count() << " s" << std::endl;

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

        // Randomly create a plane coordinate within the bounding box
        float px = mesh.m_boundingBox[0].m_x + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (mesh.m_boundingBox[1].m_x - mesh.m_boundingBox[0].m_x);
        float py = mesh.m_boundingBox[0].m_y + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (mesh.m_boundingBox[1].m_y - mesh.m_boundingBox[0].m_y);
        float pz = mesh.m_boundingBox[0].m_z + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (mesh.m_boundingBox[1].m_z - mesh.m_boundingBox[0].m_z);
        Point planeCoordinate(px, py, pz);

        // Randomly create a normal
        float nx = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float ny = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        float nz = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        Point normal(nx, ny, nz);

        PlaneNormal mirrorPlaneAlongNormal(planeCoordinate, normal);
        std::cout << "\nPlane's coordinate: " << mirrorPlaneAlongNormal.m_coordinate.m_x << ", " << mirrorPlaneAlongNormal.m_coordinate.m_y << ", " << mirrorPlaneAlongNormal.m_coordinate.m_z << std::endl;
        std::cout << "Plane's normal: " << mirrorPlaneAlongNormal.m_normal.m_x << ", " << mirrorPlaneAlongNormal.m_normal.m_y << ", " << mirrorPlaneAlongNormal.m_normal.m_z << std::endl;
        cleanUpCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
        symmetryMappingGrid(mirrorPlaneAlongNormal, mesh, cellGrid, dx, dy, dz, numTaken, numPaired, symmetryScore);
        
        auto loop1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_loop1 = loop1 - start;
        std::cout << "Symmetry mapping time: " << elapsed_loop1.count() << " s" << std::endl;

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
            } else {
                meshVertices.push_back({{mesh.m_vertices[i].m_x, mesh.m_vertices[i].m_y, mesh.m_vertices[i].m_z}, {0.0f, 0.0f, 1.0f}});
            }
        }

        for (const auto& face : mesh.m_faces) {
            for (const auto& index : face) {
                meshIndices.push_back(index);
            }
        }
        exportOBJ("output_" + std::to_string(outputNum) + ".obj", meshVertices, meshIndices, mirrorPlaneAlongNormal);
        //visualize_mesh(meshVertices, meshIndices);
        outputNum++;

        auto loop2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_loop2 = loop2 - loop1;
        std::cout << "Obj exporting time: " << elapsed_loop2.count() << " s" << std::endl;
        
    }
    
    // First manual mirror plane
    Point zero(0, 0, 0);
    Point normal1(1, 0, 0);
    PlaneNormal plane1(zero, normal1);
    std::cout << "\nNormal of plane: " << plane1.m_normal.m_x << ", " << plane1.m_normal.m_y << ", " << plane1.m_normal.m_z << std::endl;

    auto start1 = std::chrono::high_resolution_clock::now();
    cleanUpCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
    symmetryMappingGrid(plane1, mesh, cellGrid, dx, dy, dz, numTaken, numPaired, symmetryScore);
    //evaluateSymmetryCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    std::cout << "Elapsed time: " << elapsed1.count() << " s" << std::endl;

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
        } else {
            meshVertices.push_back({{mesh.m_vertices[i].m_x, mesh.m_vertices[i].m_y, mesh.m_vertices[i].m_z}, {0.0f, 0.0f, 1.0f}});
        }
    }
    for (const auto& face : mesh.m_faces) {
        for (const auto& index : face) {
            meshIndices.push_back(index);
        }
    }

    exportOBJ("output_x.obj", meshVertices, meshIndices, plane1);



    // Second manual mirror mesh
    Point normal2(0, 0, 1);
    PlaneNormal plane2(zero, normal2);
    std::cout << "\nNormal of plane: " << plane2.m_normal.m_x << ", " << plane2.m_normal.m_y << ", " << plane2.m_normal.m_z << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    cleanUpCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
    symmetryMappingGrid(plane2, mesh, cellGrid, dx, dy, dz, numTaken, numPaired, symmetryScore);
    //evaluateSymmetryCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = end2 - start2;
    std::cout << "Elapsed time: " << elapsed2.count() << " s" << std::endl;

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
        } else {
            meshVertices.push_back({{mesh.m_vertices[i].m_x, mesh.m_vertices[i].m_y, mesh.m_vertices[i].m_z}, {0.0f, 0.0f, 1.0f}});
        }
    }
    for (const auto& face : mesh.m_faces) {
        for (const auto& index : face) {
            meshIndices.push_back(index);
        }
    }

    exportOBJ("output_y.obj", meshVertices, meshIndices, plane2);

    auto total_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> total_elapsed = total_end - total_start;
    std::cout << "\n\nTotal elapsed time: " << total_elapsed.count() << " s" << std::endl;
    
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
