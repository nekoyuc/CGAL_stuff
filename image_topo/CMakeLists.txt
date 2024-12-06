cmake_minimum_required(VERSION 3.16)
project(CubeVisualization)
set(CMAKE_CXX_STANDARD 17)

find_package(opencv REQUIRED)
include_directories(image_topo ${OpenCV_INCLUDE_DIRS})
#find_package(CGAL REQUIRED OPTIONAL_COMPONENTS Qt6)
#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
#find_package(SDL2 REQUIRED)
#find_package(glm REQUIRED)
#find_package(Matplot++ REQUIRED)

#set(TARGETS matplot)
# Target aliases
#add_library(Matplot++::matplot ALIAS matplot)
#add_library(Matplot++::matplot++ ALIAS matplot)

add_executable(image_topo image_topo.cpp canvas.cpp operations.cpp)
#add_executable(is_symmetrical is_symmetrical.cpp sdl_test.cpp cell.cpp geometry.cpp file_processors.cpp operations.cpp)
#add_executable(simulated_annealing_symmetry simulated_annealing_symmetry.cpp geometry.cpp file_processors.cpp operations.cpp cell.cpp sdl_test.cpp)

target_link_libraries(image_topo PRIVATE ${OpenCV_LIBS})
#target_link_libraries(is_symmetrical PRIVATE ${SDL2_LIBRARIES} OpenGL::GL glm::glm)
#include_directories(is_symmetrical ${SDL2_INCLUDE_DIRS})

#target_link_libraries(simulated_annealing_symmetry PRIVATE ${SDL2_LIBRARIES} OpenGL::GL glm::glm Matplot++::matplot)
#include_directories(simulated_annealing_symmetry ${SDL2_INCLUDE_DIRS})

#target_compile_definitions(cube PRIVATE CGAL_USE_BASIC_VIEWER)
