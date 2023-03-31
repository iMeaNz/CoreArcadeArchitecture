/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-marie.giacomel
** File description:
** ICore.hpp
*/

#pragma once

#include <iostream>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
/**
 * @brief This namespace will contain all of the core element of
 * the project
 */
namespace arcade {
    /**
     * @brief Main interface for our core class
     * This interface is only here to give an example of the implementation
     * You don't have to use this one precisely.
     */
    class ICore {
        public:
            /**
             * @brief Main core loop, this is the method that we
             * will call and that will handle our main loop.
             */
            virtual void mainLoop() = 0;


            /**
             * @brief Set the Framerate object
             *
             * @param framerate
             */
            virtual void setFramerate(int framerate) = 0;
            /**
             * @brief Get the Framerate object
             *
             * @return int
             */
            virtual int getFramerate() const = 0;
            /**
             * @brief Set the Score object
             *
             * @param score
             */
            virtual void setScore(int score) = 0;
            /**
             * @brief This function will be called when a game is finished or the user exits a game
             * It could probably be smart to implement an observer here but i'm lazy
             * @param score
             */
            virtual int getScore() const = 0;
            /**
             * @brief Get the Player Name object
             *
             * @return std::string
             */
            virtual std::string getPlayerName() const = 0;
            /**
             * @brief Set the Player object
             *
             * @param name
             */
            virtual void setPlayerName(std::string name) = 0;


            /**
             * @brief Set the Display Module object
             *
             * @param display
             */
            virtual void setDisplayModule(display::IDisplayModule *display) = 0;
            /**
             * @brief Set the Game Module object
             *
             * @param game
             */
            virtual void setGameModule(game::IGameModule *game) = 0;
    };
}