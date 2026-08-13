#include "lui_widgets.hpp"

#include "C2Core/c2_hash.hpp"
#include "c2_ui_context.hpp"
#include "lui_input.hpp"

namespace LUI {

bool Button(UIContext& ctx, std::string_view label, const Rect& bounds) {
    bool inRect = pointInRect(ctx.mouseState.mousePos, bounds);
    uint32_t id = C2Core::Hash::fnvA1Hash(label);

    if (inRect) {
        ctx.hotItem = id;
        if (ctx.activeItem == 0 && ctx.mouseState.isJustPressed()) {
            ctx.activeItem = id;
        }
    }

    Color btnColor(0.5F, 0.5F, 0.5F, 1.0F);
    if (ctx.hotItem == id) {
        btnColor = Color(0.6F, 0.6F, 0.6F, 1.0F);
    }
    if (ctx.activeItem == id) {
        btnColor = Color(0.3F, 0.3F, 0.3F, 1.0F);
    }

    ctx.drawList.push_back({bounds, btnColor});

    if (ctx.mouseState.isJustReleased() && ctx.activeItem == id &&
        ctx.hotItem == id) {
        return true;
    }
    return false;
}

}  // namespace LUI
