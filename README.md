
# Core architecture for the arcade project
The goal of these intefaces is to have a basic starting point for the Arcade Project.   
In this project, the game modules have no idea wich library is used by the display module at runtime.  
It means that the information that the game module sends to the display module must be generic enough to be handled by any type of display module.

## The graphical design
The main idea behind this architecture is based on the IObject interface.

Your game module can contain several basic objects that MUST implement this interface. Most of theses objects will be basic shapes such as rectangle, circle, triangle or other geometrical shapes (even though I strongly advise to only use rectangles in your game, basically everything can be done using them).   

Also, each objects will have to implement a basic abstract class describing the content of the objects. This is important, because all the other will then know how to better implement the graphical design of this object. 

If you wish to add new objects, make a pull request and we will add them to the core architecture.    

Each display module will have to implement a drawing function for each of the objects present in the IObject interface and implement all of the methods of the IDisplayModule interface. So if you wish to add a new object, be certain about it, because each groups will have to implement themselves the drawing function for this object in all of the different libraries.

## The events handler
The events handler is pretty straightforward, the display modules will have method that the game module can call in order to know if a button has been pressed or not. The buttons are limited, check the IDisplayModule for more information.  

The conversion between the generic buttons/events of the IDisplayModule and the events of your concrete display module is totally up to you.

The same way, if you wish to add new buttons, make a pull request and we will add them as soon as possible.

## What about positions ?
Position in graphic mode and text mode are totally different (one uses pixel, the other columns and lines), to prevent that, I recommend that your game modules always send the positions in PIXELS.  
Then, your text display module will convert those pixel positions in cell positions. 

The implementation of this function is entirely up to you, there are ways to know approximatevely how many pixels takes a certain character on the screen, but you could just take an arbitrary constant that fits your design.

## Object example
If we take the Rectangle example, here is a very simple implementation
```C++
class Rectangle : public ARectangle {
    public:
        Rectangle() { _id = RECTANGLE;};
        virtual ~Rectangle() {};

        //Interface implementation
        Type getType() const override { return _id;};

        void setPos(IDisplayModule::Vector2i pos) {_pos = pos;};
        IDisplayModule::Vector2i getPos() const override { return _pos;};
        void setSize(IDisplayModule::Vector2i size) {_size = size;};
        IDisplayModule::Vector2i getSize() const override { return _size;};
        void setColor(IDisplayModule::Color color) {_color = color;};
        IDisplayModule::Color getColor() const {return _color;};
        //Graphic lib (SFML, SDL2)
        void setTexture(std::string path) {_pathToTexture = path;};
        std::string getTexture() const override { return _pathToTexture;};
        //Terminal graphical lib
        void setCharacter(char c) {_character = c;};
        char getCharacter() const override { return _character;};

        //Other internal logic
        int getBorderThickness() const {return _borderThickness;};
        void setBorderThickness(int thickness) {_borderThickness = thickness;};
};
```
