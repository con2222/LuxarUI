#pragma once

namespace LUI {

struct Vec2 {
    union {
        struct {
            float x = 0;
            float y = 0;
        };
        float data[2];
    };
    constexpr Vec2() = default;
    constexpr Vec2(float _x, float _y) : x(_x), y(_y) {}

    float& operator[](const int index) { return data[index]; }
    float operator[](const int index) const { return data[index]; }
};

struct Rect {
    union {
        struct {
            float x = 0;
            float y = 0;
            float w = 0;
            float h = 0;
        };
        float data[4];
    };
    constexpr Rect() = default;
    constexpr Rect(float _x, float _y, float _w, float _h)
        : x(_x), y(_y), w(_w), h(_h) {}

    float& operator[](const int index) { return data[index]; }
    float operator[](const int index) const { return data[index]; }
};

struct Color {
    union {
        struct {
            float r = 1.0F;
            float g = 1.0F;
            float b = 1.0F;
            float a = 1.0F;
        };
        float data[4];
    };
    constexpr Color() = default;
    constexpr Color(float _r, float _g, float _b, float _a)
        : r(_r), g(_g), b(_b), a(_a) {}

    float& operator[](const int index) { return data[index]; }
    float operator[](const int index) const { return data[index]; }
};

constexpr bool pointInRect(const Vec2& point, const Rect& rect) {
    return point.x >= rect.x && point.y >= rect.y &&
           point.x < (rect.x + rect.w) && point.y < (rect.y + rect.h);
}

}  // namespace LUI
