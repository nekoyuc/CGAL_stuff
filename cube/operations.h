#pragma once
#include <iostream>
#include "geometry.h"
#include "cell.h"

void constructPlane(const Point& origin, const Point& distance, PlaneNormal& plane);

void pointToIndex(const Point& p, const Point& min, const float& dx, const float& dy, const float& dz, int& x, int& y, int& z);

void mirroredPoint(const Point& p, const Plane3P& plane, Point& mirrored_p);

std::shared_ptr<CellGrid> createCellGrid(const Point& min, const Point& max, const float& dx, const float& dy, const float& dz);

void mirroredPointAlongPlaneNormal(const Point& p, const PlaneNormal& Plane, Point& mirrored_p);

void symmetryMappingGrid(const PlaneNormal& plane, const Mesh& mesh, std::shared_ptr<CellGrid>& cellGrid, const float dx, const float dy, const float dz, int& numTaken, int& numPaired, float& symmetryScore);

void cleanUpCellGrid(const std::shared_ptr<CellGrid>& cellGrid, int& numTaken, int& numPaired, float& symmetryScore);