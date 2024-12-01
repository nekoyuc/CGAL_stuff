#pragma once

#include <OpenGL/gl3.h>
#include <vector>

struct Vertex {
  GLfloat position[3];
  GLfloat color[3];
};

void visualize_mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices);