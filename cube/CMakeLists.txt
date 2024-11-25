cmake_minimum_required(VERSION 3.16)
project(CubeVisualization)

find_package(CGAL REQUIRED OPTIONAL_COMPONENTS Qt6)

add_executable(cube cube.cpp)
add_executable(is_symmetrical is_symmetrical.cpp)

target_link_libraries(cube PRIVATE CGAL::CGAL Qt6::Widgets Qt6::OpenGL)
target_compile_features(cube PRIVATE cxx_std_17)

target_compile_definitions(cube PRIVATE CGAL_USE_BASIC_VIEWER)

if(CGAL_Qt6_FOUND)
  target_link_libraries(cube PUBLIC CGAL::CGAL_Basic_viewer)
else()
  message(STATUS "NOTICE: The example 'cube' requires Qt6, and will not be compiled.")
endif()