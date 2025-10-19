#pragma once

#ifndef MESHFILTER_HPP
#define MESHFILTER_HPP

#include <core/gfx/mesh.hpp>

// I stole the name from unity.
struct MeshFilter {
public:
    MeshFilter(Mesh mesh) : mesh(mesh)
    {}

    Mesh mesh;

    // has this mesh been buffered to the GPU yet?
    bool buffered;
};

#endif
