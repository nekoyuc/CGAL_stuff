#pragma once

class Cell {
public:
    bool m_taken = false;
    bool m_paired = false;
};

class CellGrid {
public:
    CellGrid(int x, int y, int z);
    ~CellGrid();

    void set(int x, int y, int z, const Cell& cell);
    Cell* get(int x, int y, int z);
    void reset();
    void getDimensions(int& x, int& y, int& z);
    int size();

private:
    Cell* m_cells;
    int m_x = 0;
    int m_y = 0;
    int m_z = 0;
};
