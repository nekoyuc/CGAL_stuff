#include "cell.h"
#include "assert.h"
#include <memory>

CellGrid::CellGrid(int x, int y, int z) {
    m_x = x;
    m_y = y;
    m_z = z;
    m_cells = new Cell[x * y * z];
}
CellGrid::~CellGrid() {delete[] m_cells;}

void CellGrid::set(int x, int y, int z, const Cell& cell) {
    assert(x >= 0 && x < m_x);
    assert(y >= 0 && y < m_y);
    assert(z >= 0 && z < m_z);
    m_cells[z * m_x * m_y + y * m_x + x] = cell;
}

Cell* CellGrid::get(int x, int y, int z) { // return a pointer to a cell
    if (x < 0 || x >= m_x) return nullptr;
    if (y < 0 || y >= m_y) return nullptr;
    if (z < 0 || z >= m_z) return nullptr;
    return &(m_cells[z * m_x * m_y + y * m_x + x]);
}

void CellGrid::reset() {memset(m_cells, 0, m_x * m_y * m_z * sizeof(Cell));}

void CellGrid::getDimensions(int& x, int& y, int& z) {
    x = m_x;
    y = m_y;
    z = m_z;
}

int CellGrid::size() {return m_x * m_y * m_z;}

std::shared_ptr<CellGrid> createCellGrid(const Point& min, const Point& max, const float& dx, const float& dy, const float& dz) {
    std::shared_ptr<CellGrid> cg = std::make_shared<CellGrid>(static_cast<int>(std::ceil((max.m_x - min.m_x) / dx)),
                      static_cast<int>(std::ceil((max.m_y - min.m_y) / dy)),
                      static_cast<int>(std::ceil((max.m_z - min.m_z) / dz)));
    return cg;
}
// shared_ptr is slightly slightly slightly less efficient than a pointer, automatically deletes memory when it goes out of scope