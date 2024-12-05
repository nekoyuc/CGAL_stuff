#include "operations.h"

void pointToIndex(const Point& p, const Point& min, const float& dx, const float& dy, const float& dz, int& x, int& y, int& z) {
    x = static_cast<int>(std::floor((p.m_x - min.m_x) / dx));
    y = static_cast<int>(std::floor((p.m_y - min.m_y) / dy));
    z = static_cast<int>(std::floor((p.m_z - min.m_z) / dz));
}

void mirroredPoint(const Point& p, const Plane3P& plane, Point& mirrored_p) {
    float d = (p.m_x - plane.m_points[0].m_x) * plane.m_normal.m_x +
              (p.m_y - plane.m_points[0].m_y) * plane.m_normal.m_y +
              (p.m_z - plane.m_points[0].m_z) * plane.m_normal.m_z;
    mirrored_p.m_x = p.m_x - 2 * d * plane.m_normal.m_x;
    mirrored_p.m_y = p.m_y - 2 * d * plane.m_normal.m_y;
    mirrored_p.m_z = p.m_z - 2 * d * plane.m_normal.m_z;
}

void mirroredPointAlongPlaneNormal(const Point& p, const PlaneNormal& Plane, Point& mirrored_p) {
    float d = (p.m_x - Plane.m_coordinate.m_x) * Plane.m_normal.m_x +
              (p.m_y - Plane.m_coordinate.m_y) * Plane.m_normal.m_y +
              (p.m_z - Plane.m_coordinate.m_z) * Plane.m_normal.m_z;
    mirrored_p.m_x = p.m_x - 2 * d * Plane.m_normal.m_x;
    mirrored_p.m_y = p.m_y - 2 * d * Plane.m_normal.m_y;
    mirrored_p.m_z = p.m_z - 2 * d * Plane.m_normal.m_z;
}

void symmetryMappingGrid(const PlaneNormal& plane, const Mesh& mesh, std::shared_ptr<CellGrid>& cellGrid, const float dx, const float dy, const float dz, int& numTaken, int& numPaired, float& symmetryScore) {
    for (int i = 0; i < mesh.m_vertices.size(); i++) {
        int x = 0;
        int y = 0;
        int z = 0;
        pointToIndex(mesh.m_vertices[i], mesh.m_boundingBox[0], dx, dy, dz, x, y, z); // based on bounding box
        Cell* cell = cellGrid->get(x, y, z);
        if (cell->m_taken == true) {
            continue;
        } else {
            cell->m_taken = true;
            numTaken++;
            Point mirrored_p(0,0,0);
            mirroredPointAlongPlaneNormal(mesh.m_vertices[i], plane, mirrored_p);
            int mirrored_x = 0;
            int mirrored_y = 0;
            int mirrored_z = 0;
            pointToIndex(mirrored_p, mesh.m_boundingBox[0], dx, dy, dz, mirrored_x, mirrored_y, mirrored_z); // based on bounding box
            Cell* mirrored_cell = cellGrid->get(mirrored_x, mirrored_y, mirrored_z);
            if (mirrored_cell != nullptr) {
                if (mirrored_cell->m_taken == true) {
                    cell->m_paired = true;
                    numPaired++;
                    if (mirrored_cell->m_paired == false) {
                        mirrored_cell->m_paired = true;
                        numPaired++;
                    }
                }
            } else {
                continue;
            }
        }
    }
    symmetryScore = static_cast<float>(numPaired) / static_cast<float>(numTaken);
}

void cleanUpCellGrid(const std::shared_ptr<CellGrid>& cellGrid, int& numTaken, int& numPaired, float& symmetryScore) {
    cellGrid->reset();
    numTaken = 0;
    numPaired = 0;
    symmetryScore = 0;
}