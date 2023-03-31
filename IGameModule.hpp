/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-marie.giacomel
** File description:
** IGameModule.hpp
*/

#pragma once

#include "IDisplayModule.hpp"

/**
 * @brief This is the namespace that will contain all of your games
 */
namespace game {
    /**
     * @brief Interface handling all the stuff about our games
     * All of our games must implement this interface
     */
    class IGameModule {
        public:
            virtual ~IGameModule() = default;


            /**
             * @brief This function will be called when starting the program or
             * when switching to another graphic library. It will fill all the necessary
             * objects of the game.
             */
            virtual void init() = 0;
            /**
             * @brief This function will handle all the objects based on certain events
             *
             * @param display
             */
            virtual void update(display::IDisplayModule *display) = 0;
            /**
             * @brief This function will be called when closing the game/switching
             * games. It should destroy the object itself to avoid memory leaks
             */
            virtual void stop() = 0;
    };
}

//Check IDisplayModule for documentation
//extern "C" IGameModule *entryPointGame();