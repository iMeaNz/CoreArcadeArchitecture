/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-marie.giacomel
** File description:
** IDisplayModule.hpp
*/

#pragma once

#include <iostream>
#include <memory>
namespace object {
    class IObject;
}
/**
 * @brief This namespace will contains all of are graphic libraries
 */
namespace display {
    //Struct used to handle positions
    struct Vector2i {
        int x;
        int y;
        Vector2i& operator=(const Vector2i& other) = default;
        bool operator==(const Vector2i &other) const {
            return (x == other.x && y == other.y);
        }
    };

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
        SPACE, //Space
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
     * @brief Interface handling all the drawing
     * All of our graphic classes must implement this interface
     */
    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;


            /**
             * @brief This function will be called when starting the program or
             * when switching to another graphic library
             */
            virtual void init(Vector2i windowSize) = 0;
            /**
             * @brief This function will handle the closing of the display
             * library (closing the window in SFML for example)
             * This function MUST also delete the instance itself to avoid
             * memory leaks
             */
            virtual void close() = 0;


            /**
             * @brief Checks if a certain button has been pressed
             *
             * @param button
             * @return true
             * @return false
             */
            virtual bool isButtonPressed(Button button) = 0;


            /**
             * @brief Main display function, it will take an IObject and draw it onto the screen
             * based on his type
             * @param obj
             */
            virtual void drawObj(std::shared_ptr<object::IObject> obj) = 0;
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
             * @brief This function will fill all the events of your game
             * In SFML for example, this is the function where you will
             * use the pollEvents function
             */
            virtual void handleEvents() = 0;
    };
}

//You have to implement in each lib a C entryPoint() function or anything similar that returns
//an instance of your class. So that your Loader can load the .so file generated.
//extern "C" IDisplayModule *entryPointDisplay();
