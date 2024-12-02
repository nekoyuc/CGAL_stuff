#pragma once
#include <iostream>
#include "geometry.h"
#include "cell.h"

void pointToIndex(const Point& p, const Point& min, const float& dx, const float& dy, const float& dz, int& x, int& y, int& z);

void mirroredPoint(const Point& p, const Plane3P& plane, Point& mirrored_p);

void mirroredPointAlongPlaneNormal(const Point& p, const PlaneNormal& Plane, Point& mirrored_p);

void symmetryMappingGrid(const PlaneNormal& plane, const Mesh& mesh, std::shared_ptr<CellGrid>& cellGrid,
const float dx, const float dy, const float dz, int& numTaken, int& numPaired, float& symmetryScore);

void cleanUpCellGrid(const std::shared_ptr<CellGrid>& cellGrid, int& numTaken, int& numPaired, float& symmetryScore);