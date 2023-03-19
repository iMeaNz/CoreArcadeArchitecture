/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-marie.giacomel
** File description:
** IGameModule.hpp
*/

#pragma once

#include "IDisplayModule.hpp"
/**
 * @brief Interface handling all the stuff about our games
 * All of our games must implement this interface
 */
class IGameModule {
    public:
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
        virtual void update(std::unique_ptr<IDisplayModule> &display) = 0;
};

//Check IDisplayModule for documentation
//extern "C" std::unique_ptr<IGameModule> entryPointGame();