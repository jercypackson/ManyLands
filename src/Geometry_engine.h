#pragma once

// glm
#include <glm/glm.hpp>
// gl3w
#if !defined(WIN32) || defined(__EMSCRIPTEN__)
#include <GLES3/gl3.h>  // Use GL ES 3
#else
#include <GL/gl3w.h>
#endif
// std
#include <vector>

struct Mesh;

// The class provides a convenient way to draw a mesh objects
class Geometry_engine
{
private:
    struct Array_data
    {
        glm::vec4 vert;
        glm::vec3 norm;
        glm::vec4 color;
    };

public:
    Geometry_engine();
    ~Geometry_engine();
    Geometry_engine(const Mesh& m);
    void create(const Mesh& m);
    void draw_object();

private:
    std::vector<Array_data> vnc_vector; // vertices + normals + colors
    std::vector<GLuint> indices;

    GLuint array_buff_id_;
    GLuint index_buff_id_;
};
