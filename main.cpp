/*
Author : Kuntima
Description : Immediate Mode
Date : 17/08/2018
Usage :  g++ -std=c++11 main.cpp Display.cpp -o run -lSDL2 -lGL -lGLEW
		./run
Note : A lot can be changed, this is nothing more than a prototype that I created to train myself, my goal is to do  3D Game.
*/

#include <iostream>
#include <SDL2/SDL.h>
#include "Display.h"

int main(int argc, char* argv[] ){

    /// Create a Display object
    Display display;
    /// Callling the function that displays the rotating triangles in the screen
    display.DisplayWindow() ;


    return 0;
}
