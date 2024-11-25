#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_3.h>
#include <CGAL/point_generators_3.h>
#include <CGAL/draw_triangulation_3.h>
#include <CGAL/Random_points_in_cube_3.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_3<K>                   DT3;
typedef CGAL::Creator_uniform_3<double,K::Point_3>          Creator;

int main()
{
  std::vector<K::Point_3> cube_points;
CGAL::Random_points_in_cube_3<K::Point_3> cube_gen(1.0);
std::copy_n(cube_gen, 50, std::back_inserter(cube_points));

DT3 dt3_cube(cube_points.begin(), cube_points.end());

CGAL::draw(dt3_cube);

  return EXIT_SUCCESS;
}


