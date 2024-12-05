#include "part.h"
#include <CGAL/simple_cartesian.h>
#include <CGAL/Plane_3.h>
#include <CGAL/Point_3.h>


typedef CGAL::Simple_cartesian<double> S;

int main() {
    Part object;
    object.create_mesh();

    Part slicer;
    slicer.create_mesh();

    CGAL::Point_3<S> p1(0, 0, 0);
    CGAL::Point_3<S> p2(1, 0, 0);
    CGAL::Point_3<S> p3(0, 1, 0);
    CGAL::Point_3<S> p4(0, 0, 1);

    CGAL::Plane_3<S> plane(1, 2, 3);
    return 0;
}