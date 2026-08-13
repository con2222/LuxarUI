#pragma once

#include "c2_ui_math.hpp"

namespace LUI {

struct InputState {
    Vec2 mousePos;
    bool isLeftDown = false;
    bool wasLeftDown = false;

    bool isHeld() const { return isLeftDown; }
    bool isJustPressed() const { return isLeftDown && !wasLeftDown; }
    bool isJustReleased() const { return !isLeftDown && wasLeftDown; }
};

}  // namespace LUI
