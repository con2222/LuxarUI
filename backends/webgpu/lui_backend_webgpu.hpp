#pragma once

#include <cstdint>
#include <vector>

#include "../../include/c2_ui_math.hpp"

namespace LUI {

struct DrawCommand;

struct Vertex {
    Vec2 point;   // X, Y
    Color color;  // RGBA
};

struct WebGPURenderer {
    void buildGeometry(const std::vector<DrawCommand>& commands,
                       std::vector<Vertex>& vertices,
                       std::vector<uint16_t>& indices);
};

}  // namespace LUI
