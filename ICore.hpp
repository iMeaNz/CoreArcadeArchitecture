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

class ICore {
    public:
        virtual void mainLoop() = 0;

        virtual void setFramerate(int framerate) = 0;
        virtual void addScore(int score) = 0;
        virtual std::string getPlayerName() const = 0;

        virtual void setDisplayModule(IDisplayModule *display) = 0;
        virtual void setGameModule(IGameModule *game) = 0;
};