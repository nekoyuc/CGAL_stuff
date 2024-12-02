#include "geometry.h"
#include "operations.h"

Point coordinate(0,0,0);
Point normal1(1,1,1);

Point distance(3,0,3);
Point normal2(0,4,4);

Point distance1(5,5,5);
Point distance2(6,6,6);

PlaneNormal plane(coordinate, normal1);


int main() {
std::cout << "\nCoordinate of plane: " << plane.m_coordinate.m_x << ", " << plane.m_coordinate.m_y << ", " << plane.m_coordinate.m_z << std::endl;
std::cout << "Normal of plane: " << plane.m_normal.m_x << ", " << plane.m_normal.m_y << ", " << plane.m_normal.m_z << std::endl;
reconstructPlaneNormalByDistance(distance, normal2, plane);
std::cout << "\nCoordinate of plane: " << plane.m_coordinate.m_x << ", " << plane.m_coordinate.m_y << ", " << plane.m_coordinate.m_z << std::endl;
std::cout << "Normal of plane: " << plane.m_normal.m_x << ", " << plane.m_normal.m_y << ", " << plane.m_normal.m_z << std::endl;
distance.m_x = 7;
distance.m_y = 7;
distance.m_z = 7;
normal2.m_x = 8;
normal2.m_y = 8;
normal2.m_z = 8;
std::cout << "\nCoordinate of plane: " << plane.m_coordinate.m_x << ", " << plane.m_coordinate.m_y << ", " << plane.m_coordinate.m_z << std::endl;
std::cout << "Normal of plane: " << plane.m_normal.m_x << ", " << plane.m_normal.m_y << ", " << plane.m_normal.m_z << std::endl;

distance1 = distance2;
std::cout << "\nDistance1: " << distance1.m_x << ", " << distance1.m_y << ", " << distance1.m_z << std::endl;
distance2.m_x = 9;
distance2.m_y = 9;
distance2.m_z = 9;
std::cout << "Distance1: " << distance1.m_x << ", " << distance1.m_y << ", " << distance1.m_z << std::endl;
}