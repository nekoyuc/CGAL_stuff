#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GLUT/glut.h>
#include "geometry.h"
#include "sdl_test.h"

void loadOBJ(const std::string& filename, Mesh& mesh);

void exportOBJ(const std::string &filename, const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices, const PlaneNormal &mirrorPlane);