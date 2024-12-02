#include <fstream>
#include <iostream>
#include <matplot/matplot.h>

#include "geometry.h"
#include "file_processors.h"
#include "cell.h"
#include "operations.h"
#include "sdl_test.h"

int main() {
    std::string filename = "../../assembly_planner/models/indoor_plant_02.obj";
    Mesh mesh(100000);
    loadOBJ(filename, mesh);
    
    // Create cell map
    float dx = 0.3;
    float dy = 0.3;
    float dz = 0.3;
    
    std::shared_ptr<CellGrid> cellGrid = createCellGrid(mesh.m_boundingBox[0], mesh.m_boundingBox[1], dx, dy, dz);

    // check symmetry
    int numTaken = 0;
    int numPaired = 0;
    float previousSymmetryScore = 0;
    float symmetryScore = 0;
    int outputNum = 0;

    // Visualization of the loaded mesh
    std::vector<Vertex> meshVertices;
    std::vector<GLuint> meshIndices;

    float temperature = 1;
    float coolingRate = 0.92;
    float distance_length = sqrt((mesh.m_boundingBox[1].m_x - mesh.m_boundingBox[0].m_x) * (mesh.m_boundingBox[1].m_x - mesh.m_boundingBox[0].m_x) +
                                 (mesh.m_boundingBox[1].m_y - mesh.m_boundingBox[0].m_y) * (mesh.m_boundingBox[1].m_y - mesh.m_boundingBox[0].m_y) +
                                 (mesh.m_boundingBox[1].m_z - mesh.m_boundingBox[0].m_z) * (mesh.m_boundingBox[1].m_z - mesh.m_boundingBox[0].m_z))/4;
    float distance_length_decay_rate = 0.99;
                                 
    
    Point current_coordinate(0, 0, 0);
    Point distance(0, 0, 0);
    Point initial_normal(0, 0, 1);
    PlaneNormal plane(current_coordinate, initial_normal);

    // Plot symmetry score overtime
    std::vector<float> symmetryScores;
    std::vector<float> temperatures;
    std::vector<float> distances;
    int iteration = 0;
    
    auto start_time = std::chrono::high_resolution_clock::now();
    while (distance_length > 0.0001) {
        float phi = static_cast <float> (rand() / static_cast <float> (RAND_MAX)) * 2 * 3.14159265359;
        float theta = static_cast <float> (rand() / static_cast <float> (RAND_MAX)) * 3.14159265359;
        distance.m_x = distance_length * sin(theta) * cos(phi);
        distance.m_y = distance_length * sin(theta) * sin(phi);
        distance.m_z = distance_length * cos(theta);
        //distance.m_x = mesh.m_boundingBox[0].m_x + static_cast <float> (rand() / static_cast <float> (RAND_MAX)) * (mesh.m_boundingBox[1].m_x - mesh.m_boundingBox[0].m_x);
        //distance.m_y = mesh.m_boundingBox[0].m_y + static_cast <float> (rand() / static_cast <float> (RAND_MAX)) * (mesh.m_boundingBox[1].m_y - mesh.m_boundingBox[0].m_y);
        //distance.m_z = mesh.m_boundingBox[0].m_z + static_cast <float> (rand() / static_cast <float> (RAND_MAX)) * (mesh.m_boundingBox[1].m_z - mesh.m_boundingBox[0].m_z);
        reconstructPlaneNormalByDistance(current_coordinate, distance, plane);
        cleanUpCellGrid(cellGrid, numTaken, numPaired, symmetryScore);
        symmetryMappingGrid(plane, mesh, cellGrid, dx, dy, dz, numTaken, numPaired, symmetryScore);
        if (symmetryScore > previousSymmetryScore) {
            previousSymmetryScore = symmetryScore;
            symmetryScores.push_back(symmetryScore);
            current_coordinate = distance;
            distance_length *= distance_length_decay_rate;
            temperatures.push_back(temperature);
            distances.push_back(distance_length);
        } else if (static_cast <float> (rand() / static_cast <float> (RAND_MAX)) < temperature) {
            previousSymmetryScore = symmetryScore;
            symmetryScores.push_back(symmetryScore);
            current_coordinate = distance;
            temperature *= coolingRate;
            temperatures.push_back(temperature);
            distances.push_back(distance_length);
        } else {
            distance_length *= distance_length_decay_rate;
            symmetryScores.push_back(previousSymmetryScore);
            temperatures.push_back(temperature);
            distances.push_back(distance_length);
        }
        //std::cout << "Symmetry score: " << symmetryScore << std::endl;
        iteration++;
    }

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
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;
    std::cout << "Iteration: " << iteration << std::endl;
    std::cout << "Elapsed time: " << elapsed_time.count() << " s" << std::endl;

    exportOBJ("output_final.obj", meshVertices, meshIndices, plane);

    std::cout << "Final symmetry score: " << previousSymmetryScore << std::endl;
    std::cout << "Final coordinate: " << current_coordinate.m_x << ", " << current_coordinate.m_y << ", " << current_coordinate.m_z << std::endl;
    
    // Plot the symmetry scores, temperatures, and distances
    auto fig = matplot::figure(true);
    matplot::plot(symmetryScores)->line_width(2).display_name("Symmetry Scores");   
    matplot::hold(matplot::on);
    matplot::plot(temperatures)->line_width(2).display_name("Temperatures");
    matplot::plot(distances)->line_width(2).display_name("Distances");
    matplot::legend();
    matplot::title("Symmetry Scores, Temperatures, and Distances Over Time");
    matplot::xlabel("Iteration");
    matplot::ylabel("Values");
    fig->size(1920, 1080); // Set the figure size for higher resolution
    matplot::save("output/symmetry_plot.png");
    system("open output/symmetry_plot.png");
    //matplot::show();
    /*
    // Plot the symmetry scores, temperatures, and distances
    auto fig = matplot::figure(true);
    auto ax1 = fig->add_axes();
    ax1->plot(symmetryScores)->line_width(2).display_name("Symmetry Scores");
    ax1->ylabel("Symmetry Scores");
    ax1->legend();

    auto ax2 = fig->add_axes();
    ax2->plot(temperatures)->line_width(2).display_name("Temperatures");
    ax2->ylabel("Temperatures");
    ax2->legend();

    auto ax3 = fig->add_axes();
    ax3->plot(distances)->line_width(2).display_name("Distances");
    ax3->ylabel("Distances");
    ax3->legend();

    matplot::title("Symmetry Scores, Temperatures, and Distances Over Time");
    matplot::xlabel("Iteration");
    matplot::show();
    */
    return 0;
}