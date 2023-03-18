
# Core architecture for the arcade project
The goal of these intefaces is to have a basic starting point for the Arcade Project. In this project, the game modules have no idea wich library is used by the display module at runtime. It means that the information that the game module sends to the display module must be generic enough to be handled by any type of display module.

## The graphical design
The main idea behind this architecture is based on the IObject interface. Your game module can contain several basic objects that MUST implement this interface. Most of theses objects will be basic shapes such as rectangle, circle, triangle or other geometrical shapes (even though I strongly advise to only use rectangles in your game, basically everything can be done using them). If you wish to add new objects, make a pull request and we will add them to the core architecture.
Each display module will have to implement a drawing function for each of the objects present in the IObject interface and implement all of the methods of the IDisplayModule interface. So if you wish to add a new objects, be certain about it, because each groups will have to implement themselves the drawing function for thi object in all the different libraries.

## The events handler
The events handler is pretty straightforward, the display modules will have method that the game module can call in order to know if a button has been pressed or not. The buttons are limited, check the IDisplayModule for more information.
The conversion between the generic buttons/events of the IDisplayModule and the events of your concrete display module is totally up to you.
The same way, if you wish to add new buttons, make a pull request and we will add them as soon as possible.

## What about positions ?
Position in graphic mode and text mode are totally different (one uses pixel, the other columns and lines), to prevent that, I recommend that your game modules always send the positions in PIXELS. Then, your text display module will convert those pixel positions in cell positions. The implementation of this function is entirely up to you, there are ways to know approximatevely how many pixels takes a certain character on the screen, but you could just take an arbitrary constant that fits your design.
