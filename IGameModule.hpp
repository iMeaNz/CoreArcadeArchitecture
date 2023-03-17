/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-marie.giacomel
** File description:
** IGameModule.hpp
*/

#pragma once

#include "IDisplayModule.hpp"

class IGameModule {
    public:
        virtual void init() = 0;
        virtual void update(IDisplayModule *display) = 0;
};