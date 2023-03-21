/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-marie.giacomel
** File description:
** IObject.hpp
*/

#pragma once

#include "IDisplayModule.hpp"
/**
 * @brief Enum storing all of our objects types (even if in my honest opinion,
 * you can do basically everything using only rectangles)
 *
 */
enum Type {
    RECTANGLE,
};

/**
 * @brief This interface is extremely important, it will hold all of the necessary
 * informations of our objects used when drawing them. If you wish to add a new
 * object, make sure to notify others members, so we can update our enums
 */
class IObject {
    public:
        /**
         * @brief Get the Type object
         *
         * @return Type
         */
        virtual Type getType() const = 0;
        /**
         * @brief Set the Pos object
         *
         * @param pos
         */
        virtual void setPos(IDisplayModule::Vector2i pos) = 0;
        /**
         * @brief Get the Pos object
         *
         * @return IDisplayModule::Vector2i
         */
        virtual IDisplayModule::Vector2i getPos() const = 0;
        /**
         * @brief Set the Size object
         *
         * @param size
         */
        virtual void setSize(IDisplayModule::Vector2i size) = 0;
        /**
         * @brief Get the Size object
         *
         * @return IDisplayModule::Vector2i
         */
        virtual IDisplayModule::Vector2i getSize() const = 0;
        /**
         * @brief Set the Texture object
         *
         * @param path
         */
        virtual void setTexture(std::string path) = 0;
        /**
         * @brief Get the Texture object
         *
         * @return std::string
         */
        virtual std::string getTexture() const = 0;
        /**
         * @brief Set the Character object
         *
         * @param c
         */
        virtual void setCharacter(char c) = 0;
        /**
         * @brief Get the Character object
         *
         * @return char
         */
        virtual char getCharacter() const = 0;
        /**
         * @brief Set the Character Color object
         *
         * @param color
         */
        virtual void setCharacterColor(IDisplayModule::Color color) = 0;
        /**
         * @brief Get the Character Color object
         *
         * @return IDisplayModule::Color
         */
        virtual IDisplayModule::Color getCharacterColor() const = 0;
        /**
         * @brief Set the Color object
         *
         * @param color
         */
        virtual void setColor(IDisplayModule::Color color) = 0;
        /**
         * @brief Get the Color object
         *
         * @return IDisplayModule::Color
         */
        virtual IDisplayModule::Color getColor() const = 0;
};
/**
 * @brief Example of abstract class, I thought about those because it will make
 * the collaboration between our groups better. This way, we all know what is
 * contained in a new object.
 *
 */
class ARectangle : public IObject {
    protected:
        Type _id;

        IDisplayModule::Vector2i _pos;
        IDisplayModule::Vector2i _size;
        std::string _pathToTexture;
        //For example here, _borderThickness is not common amongst all
        //the IObject
        int _borderThickness;
        IDisplayModule::Color _color;
        IDisplayModule::Color _characterColor;
        char _character;
};

