#include <cstdint>
#include <iostream>

// Подключаем твои модули
#include "c2_ui_context.hpp"
#include "lui_input.hpp"
#include "lui_widgets.hpp"

// Если у тебя другой синтаксис логгера, поправь вызовы C2Core::Log::info
// #include "c2_log.hpp"

using namespace LUI;

// Вспомогательная функция для эмуляции одного кадра игры
void SimulateFrame(UIContext& ctx, const InputState& input, int frameNumber) {
    std::cout << "--- Кадр " << frameNumber << " ---" << std::endl;

    // 1. Начало кадра (обновляем инпут и сбрасываем hotItem)
    ctx.beginFrame(input);

    // 2. Создаем кнопку: x=10, y=10, ширина=100, высота=50
    Rect buttonBounds(10.0f, 10.0f, 100.0f, 50.0f);
    uint32_t buttonId = 12345;  // Условный хеш нашей кнопки

    // 3. Вызываем логику кнопки
    bool clicked = Button(ctx, "daubi", buttonBounds);

    // 4. Логируем результат
    if (clicked) {
        // Здесь используй свой цветной логгер, например C2Core::Log::info
        std::cout << "[УСПЕХ] КНОПКА НАЖАТА!" << std::endl;
    }

    std::cout << "Hot: " << ctx.hotItem << " | Active: " << ctx.activeItem
              << "\n\n";

    // 5. Конец кадра (сбрасываем activeItem, если мышь отпущена)
    ctx.endFrame();
}

int main() {
    UIContext ctx;
    InputState input;

    std::cout << "ТЭСТ 1: ИДЕАЛЬНЫЙ КЛИК\n";

    // Кадр 1: Навели мышку на кнопку (Hover)
    input.mousePos = {50.0f, 30.0f};  // Внутри прямоугольника
    input.wasLeftDown = false;
    input.isLeftDown = false;
    SimulateFrame(ctx, input, 1);

    // Кадр 2: Нажали левую кнопку (JustPressed)
    input.wasLeftDown = false;
    input.isLeftDown = true;
    SimulateFrame(ctx, input, 2);

    // Кадр 3: Удерживаем кнопку нажатой (Held)
    input.wasLeftDown = true;
    input.isLeftDown = true;
    SimulateFrame(ctx, input, 3);

    // Кадр 4: Отпустили кнопку, не уводя мышь (JustReleased -> КЛИК!)
    input.wasLeftDown = true;
    input.isLeftDown = false;
    SimulateFrame(ctx, input, 4);

    std::cout << "ТЭСТ 2: ПЕРЕДУМАЛ (УВЕЛ МЫШЬ)\n";

    // Кадр 5: Снова нажали левую кнопку (JustPressed)
    input.wasLeftDown = false;
    input.isLeftDown = true;
    SimulateFrame(ctx, input, 5);

    // Кадр 6: Удерживая кнопку, увели мышь ЗА пределы кнопки
    input.mousePos = {200.0f, 200.0f};  // Координаты вне прямоугольника
    input.wasLeftDown = true;
    input.isLeftDown = true;
    SimulateFrame(ctx, input, 6);

    // Кадр 7: Отпустили кнопку вне элемента (JustReleased -> НИЧЕГО!)
    input.wasLeftDown = true;
    input.isLeftDown = false;
    SimulateFrame(ctx, input, 7);

    return 0;
}
