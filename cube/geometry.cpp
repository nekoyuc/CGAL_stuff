#include "geometry.h"

Point::Point(float x, float y, float z){
            m_x = x;
            m_y = y;
            m_z = z;
        }

Point::~Point() {} //Can this be deleted?

Mesh::Mesh(int reserveSize) : m_boundingCenter(0,0,0) { //constructor
            m_vertices.reserve(reserveSize);
            m_faces.reserve(reserveSize*3);
            m_boundingBox.push_back(Point(0,0,0));
            m_boundingBox.push_back(Point(0,0,0));
        }

Mesh::~Mesh() {} // Can this be deleted?

void Mesh::addPoint(Point& p) {
    m_vertices.push_back(p);
}

Plane3P::Plane3P(Point& p1, Point& p2, Point& p3) : m_normal(0, 0, 0) { //why does m_normal need to be initialized here?
            m_points.push_back(p1);
            m_points.push_back(p2);
            m_points.push_back(p3);
            calculateNormal(m_points[0], m_points[1], m_points[2], m_normal);    
        }

Plane3P::~Plane3P() {} // Can this be deleted?

void Plane3P::calculateNormal(Point& p1, Point& p2, Point& p3, Point& normal) {
            float u1 = p2.m_x - p1.m_x;
            float u2 = p2.m_y - p1.m_y;
            float u3 = p2.m_z - p1.m_z;

            float v1 = p3.m_x - p1.m_x;
            float v2 = p3.m_y - p1.m_y;
            float v3 = p3.m_z - p1.m_z;

            float w_x = u2 * v3 - u3 * v2;
            float w_y = u3 * v1 - u1 * v3;
            float w_z = u1 * v2 - u2 * v1;

            float w_length = sqrt(w_x * w_x + w_y * w_y + w_z * w_z);
            
            normal.m_x = w_x / w_length;
            normal.m_y = w_y / w_length;
            normal.m_z = w_z / w_length;
        }

PlaneNormal::PlaneNormal(Point &coordinate, Point &normal) : m_coordinate(0, 0, 0), m_normal(0, 0, 0) {
            m_coordinate = coordinate;
            m_normal = normal;
            calculateNormal(m_normal);
        }

PlaneNormal::~PlaneNormal(){} // Can this be delted?

void PlaneNormal::calculateNormal(Point& normal) {
            float normalLength = sqrt(normal.m_x * normal.m_x + normal.m_y * normal.m_y + normal.m_z * normal.m_z);
            normal.m_x = normal.m_x / normalLength;
            normal.m_y = normal.m_y / normalLength;
            normal.m_z = normal.m_z / normalLength;
        }