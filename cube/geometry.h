#pragma once
#include <vector>

class Point{
    public:
        Point(float x, float y, float z);
        ~Point();
        float m_x;
        float m_y;
        float m_z;
};

class Mesh{
    public:
        Mesh(int reserveSize);
        ~Mesh();

        std::vector<Point> m_vertices;
        std::vector<std::vector<int>> m_faces;
        std::vector<Point> m_boundingBox;
        Point m_boundingCenter;

        void addPoint(Point &p);
};

class Plane3P{ //
    public:
        Plane3P(Point& p1, Point& p2, Point& p3);
        ~Plane3P();

        std::vector<Point> m_points;
        Point m_normal;

        void calculateNormal(Point& p1, Point& p2, Point& p3, Point& normal);
};

class PlaneNormal{
    public:
        PlaneNormal(Point &coordinate, Point &normal);
        ~PlaneNormal();

        Point m_coordinate;
        Point m_normal;

        void calculateNormal(Point& normal);
};
