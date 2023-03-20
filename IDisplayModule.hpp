/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-marie.giacomel
** File description:
** IDisplayModule.hpp
*/

#pragma once

#include <iostream>
#include <memory>

class IObject;

/**
 * @brief Interface handling all the drawing
 * All of our graphic classes must implement this interface
 */
class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        //Struct used to handle positions
        struct Vector2i {
            int x;
            int y;
        };
        /**
         * @brief This function will be called when starting the program or
         * when switching to another graphic library
         */
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
            LEFT, //Q
            UP, //Z
            RIGHT, //D
            DOWN, //S
            KEY_F, //F
            KEY_E, //E
            ESC, //Escape
            F1, //Previous graphic library
            F2, //Next graphic library
            F3, //Previous Game
            F4, //Next game
            F5, //Restart
            F6, //Menu
            F7 //Exit
        };

        /**
         * @brief Checks if a certain button has been pressed
         *
         * @param button
         * @return true
         * @return false
         */
        virtual bool isButtonPressed(Button button) const = 0;
        //Struct handling mouse button events
        struct MouseButtonEvent {
            enum class MouseButton {
                NONE,
                LEFT,
                RIGHT
            };
            enum class MouseEventType {
                NONE,
                PRESSED,
                RELEASED
            };
            MouseEventType type;
            MouseButton button;
            Vector2i pos;
        };
        /**
         * @brief Get the Mouse Pos object
         *
         * @return Vector2i
         */
        virtual Vector2i getMousePos() const = 0;
        /**
         * @brief Get the Mouse Button Event object
         *
         * @return MouseButtonEvent
         */
        virtual MouseButtonEvent getMouseButtonEvent() = 0;

        /**
         * @brief Returns true if the client wish to close the game
         *
         * @return true
         * @return false
         */
        virtual bool close() = 0;

        /**
         * @brief Main display function, it will take an IObject and draw it onto the screen
         * based on his type
         * @param obj
         */
        virtual void drawObj(IObject *obj) = 0;
        /**
         * @brief Display all the objects drawn beforehand to the screen
         *
         */
        virtual void render() = 0;
        /**
         * @brief Clears the window
         *
         * @param color
         */
        virtual void clearWindow(Color color) = 0;
        /**
         * @brief This will be the function where you will be using the pollEvent function for example
         *
         */
        virtual void handleEvents() = 0;
};

//You have to implement in each lib a C entryPoint() function or anything similar that returns
//an instance of your class. So that your Loader can load the .so file generated.
//extern "C" std::unique_ptr<IDisplayModule> entryPointDisplay();
