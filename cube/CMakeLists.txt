cmake_minimum_required(VERSION 3.16)
project(CubeVisualization)
set(CMAKE_CXX_STANDARD 17)


find_package(CGAL REQUIRED OPTIONAL_COMPONENTS Qt6)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)


add_executable(cube cube.cpp)
add_executable(is_symmetrical is_symmetrical.cpp sdl_test.cpp)
target_link_libraries(cube PRIVATE CGAL::CGAL Qt6::Widgets Qt6::OpenGL GLUT::GLUT)
target_link_libraries(cube PRIVATE CGAL::CGAL Qt6::Widgets Qt6::OpenGL OpenGL::GL)

target_compile_features(cube PRIVATE cxx_std_17)

target_link_libraries(is_symmetrical PRIVATE ${SDL2_LIBRARIES} OpenGL::GL glm::glm)
include_directories(is_symmetrical ${SDL2_INCLUDE_DIRS})

target_compile_definitions(cube PRIVATE CGAL_USE_BASIC_VIEWER)

if(CGAL_Qt6_FOUND)
  target_link_libraries(cube PUBLIC CGAL::CGAL_Basic_viewer)
else()
  message(STATUS "NOTICE: The example 'cube' requires Qt6, and will not be compiled.")
endif()