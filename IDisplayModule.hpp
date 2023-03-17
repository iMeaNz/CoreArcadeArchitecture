/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-marie.giacomel
** File description:
** IDisplayModule.hpp
*/

#pragma once

#include <iostream>
#include <memory>
#include "IObject.hpp"

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;

        struct Vector2i {
            int x;
            int y;
        };

        virtual void init(Vector2i windowSize) = 0;

        enum Color {
            BLACK,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            WHITE,
        };

        enum Button {
            LEFT,
            UP,
            RIGHT,
            DOWN,
            KEY_Q,
            KEY_E,
            ESC,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7
        };
        virtual bool isButtonPressed(Button button) const = 0;
        struct MouseButtonEvent {
            enum MouseButton {
                NONE,
                LEFT,
                RIGHT
            };
            enum MouseEventType {
                NONE,
                PRESSED,
                RELEASED
            };
            Vector2i pos;
        };
        virtual Vector2i getMousePos() const = 0;
        virtual MouseButtonEvent getMouseButtonEvent() = 0;

        virtual void close() = 0;

        virtual void render(IObject *obj) = 0;
        virtual void clear(Color color) = 0;
        virtual void handleEvents() = 0;
};

extern "C" std::unique_ptr<IDisplayModule> entryPoint();
