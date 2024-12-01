#define GL_SILENCE_DEPRECATION

#include "sdl_test.h"

#include <SDL2/SDL.h>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

class MeshRenderer {
public:
  MeshRenderer() {
    // Compile shaders and create shader program
    shaderProgram_ = createShaderProgram();
  }

  void renderMesh(const std::vector<Vertex> &vertices,
          const std::vector<GLuint> &indices,
          const glm::mat4 &model,
          const glm::mat4 &view,
          const glm::mat4 &projection) {
    // Create VAO, VBO, and EBO
    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Bind and fill VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),
           vertices.data(), GL_STATIC_DRAW);

    // Bind and fill EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
           indices.data(), GL_STATIC_DRAW);

    // Set vertex attribute pointers
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                (GLvoid *)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    // Use the shader program
    glUseProgram(shaderProgram_);

    // Set the transformation matrices
    GLuint modelLoc = glGetUniformLocation(shaderProgram_, "model");
    GLuint viewLoc = glGetUniformLocation(shaderProgram_, "view");
    GLuint projectionLoc = glGetUniformLocation(shaderProgram_, "projection");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Draw the mesh
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

    // Unbind VAO
    glBindVertexArray(0);

    // Clean up VAO, VBO, and EBO (optional)
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
  }

private:
  GLuint shaderProgram_;

  GLuint createShaderProgram() {
    // Define a simple vertex shader
    const char *vertexShaderSource = R"glsl(
      #version 330 core
      layout (location = 0) in vec3 aPos;
      layout (location = 1) in vec3 aColor;

      out vec3 ourColor;

      uniform mat4 model;
      uniform mat4 view;
      uniform mat4 projection;

      void main() {
      gl_Position = projection * view * model * vec4(aPos, 1.0);
      ourColor = aColor;
      }
    )glsl";

    // Define a simple fragment shader
    const char *fragmentShaderSource = R"glsl(
      #version 330 core
      out vec4 FragColor;
      in vec3 ourColor;

      void main() {
      FragColor = vec4(ourColor, 1.0f);
      }
    )glsl";

    // Create and compile vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Check for vertex shader compile errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
            << infoLog << std::endl;
    }

    // Create and compile fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Check for fragment shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
            << infoLog << std::endl;
    }

    // Create shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
      std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
            << infoLog << std::endl;
    }

    // Delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
  }
};

void visualize_mesh(const std::vector<Vertex> &vertices, const std::vector<GLuint> &indices) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return;
  }
  // Create a window
  SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                      SDL_WINDOWPOS_CENTERED,
                      SDL_WINDOWPOS_CENTERED,
                      640, 480, SDL_WINDOW_OPENGL);
  if (window == NULL) {
    SDL_Log("Unable to create window: %s", SDL_GetError());
    return;
  }
  // Setup an OpenGLv3 context
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GLContext glcontext = SDL_GL_CreateContext(window);
  // Print OpenGL information
  SDL_Log("OpenGL loaded");
  SDL_Log(" Vendor: %s", glGetString(GL_VENDOR));
  SDL_Log(" Renderer: %s", glGetString(GL_RENDERER));
  SDL_Log(" Version: %s", glGetString(GL_VERSION));
  SDL_Log(" Shading Language Version: %s", glGetString(GL_SHADING_LANGUAGE_VERSION));

  // Set up the OpenGL viewport
  glViewport(0, 0, 640, 480);
  // Set up the OpenGL state
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  MeshRenderer meshRenderer;

  // Define the transformation matrices
  glm::mat4 model = glm::mat4(1.0f);
  glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
                 glm::vec3(0.0f, 0.0f, 0.0f),
                 glm::vec3(0.0f, 1.0f, 0.0f));
  glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                      640.0f / 480.0f,
                      0.1f, 100.0f);

  // Main loop
  bool done = false;
  while (!done) {
    // Process events
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = true;
      }
    }
    // Render
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    meshRenderer.renderMesh(vertices, indices, model, view, projection);
    // Swap buffers
    SDL_GL_SwapWindow(window);
  }

  // Clean up
  SDL_GL_DeleteContext(glcontext);
  SDL_DestroyWindow(window);
  SDL_Quit();
}