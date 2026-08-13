#pragma once

#include <cstdint>
#include <vector>

#include "c2_ui_math.hpp"
#include "lui_input.hpp"

namespace LUI {

struct DrawCommand {
    Rect bounds;  // spot to draw
    Color color;
};

struct UIContext {
    InputState mouseState;
    std::vector<DrawCommand> drawList;
    uint32_t hotItem =
        0;  // ID of the UI element currently under the mouse cursor (hovered)
    uint32_t activeItem = 0;  // ID of the UI element currently being interacted
                              // with. Zero means no active element

    void beginFrame(const InputState& currentInput) {
        mouseState = currentInput;
        hotItem = 0;
        drawList.clear();
    }

    void endFrame() {
        if (!mouseState.isHeld()) {
            activeItem = 0;
        }
    }
};

}  // namespace LUI
