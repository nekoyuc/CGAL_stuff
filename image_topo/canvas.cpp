#include "canvas.h"

Canvas::Canvas(float width, float height, int width_cell_num, int height_cell_num) : m_layer_height(0.3f), m_max_layer(10), m_topo_grid(width_cell_num * height_cell_num) {
    m_width = width;
    m_height = height;
    m_width_cell_num = width_cell_num;
    m_height_cell_num = height_cell_num;
    m_cell_witdh = m_width / m_width_cell_num;
    m_cell_height = m_height / m_height_cell_num;
}
Canvas::~Canvas() {}

void Canvas::setSize(float width, float height) {
    m_width = width;
    m_height = height;
    m_cell_witdh = m_width / m_width_cell_num;
    m_cell_height = m_height / m_height_cell_num;
}
void Canvas::setLayerHeight(float layer_height) {
    m_layer_height = layer_height;
}
void Canvas::setCellNum(int width_cell_num, int height_cell_num) {
    m_width_cell_num = width_cell_num;
    m_height_cell_num = height_cell_num;
    m_topo_grid.resize(width_cell_num * height_cell_num);
    m_cell_witdh = m_width / m_width_cell_num;
    m_cell_height = m_height / m_height_cell_num;
}

void Canvas::getSize() {
    std::cout << "Width: " << m_width << std::endl;
    std::cout << "Height: " << m_height << std::endl;
}
void Canvas::getLayerHeight() {
    std::cout << "Layer height: " << m_layer_height << std::endl;
}
void Canvas::getCellNum() {
    std::cout << "Cell numbers in x: " << m_width_cell_num << std::endl;
    std::cout << "Cell numbers in y: " << m_height_cell_num << std::endl;
}

void Canvas::getCellSize() {
    std::cout << "Cell width: " << m_cell_witdh << std::endl;
    std::cout << "Cell height: " << m_cell_height << std::endl;
}

void Canvas::setCell(int x, int y, int value) {
    m_topo_grid[y * m_width_cell_num + x] = value;
}

// This function is for testing purposes only
void Canvas::getTopoGrid() {
    for (int i = 0; i < m_topo_grid.size(); i++) {
        std::cout << m_topo_grid[i] << " ";
    }
    std::cout << std::endl;
}
    