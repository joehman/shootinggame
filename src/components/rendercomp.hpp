#include <core/gfx/mesh.hpp>

struct MeshRender {
public:
    MeshRender(Mesh mesh) : mesh(mesh)
    {}

    Mesh mesh;

};