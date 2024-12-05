#include <CGAL/Surface_mesh.h>

typedef CGAL::Surface_mesh<S::Point_3> Mesh;

class Part {
public:
    Part() = default;

    void create_mesh() {
        // Implementation for creating the mesh
    }

private:
    Mesh m;
};