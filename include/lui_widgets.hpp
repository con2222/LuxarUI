#pragma once

#include <cstdint>
#include <string_view>

namespace LUI {

struct UIContext;
struct Rect;

bool Button(UIContext& ctx, std::string_view label, const Rect& bounds);

}  // namespace LUI
