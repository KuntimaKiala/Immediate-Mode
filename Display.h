#ifndef DISPLAY_H
#define DISPLAY_H
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <GL/glew.h>

/// the possibles states
enum class STATES { QUIT, KEEP} ;

class Display
{
    public:
        /// Constructor, it initializes everything
        Display();
        /// Destructor, destroy the window
        ~Display();
        /// The function that initializes SDL
        void initDisplay() ;
        /// The function that warns when there is an error
        void errorMessage(std :: string errorType) ;
        /// The function that make the drawings and displays it
        void draw() ;
        /// The function that controls eventHandler and  draw function
        void DisplayWindow() ;
        /// The function that handles the if QUIT
        void eventHandler() ;
        /// The function that draws the triangles
        void immediateMode() ;
        /// The function that sets the anlgle of rotate
        void rotation() ;

    private:
    SDL_Window * _window ;
    std :: string _windowName ;
    int _width ;
    int _height ;
    SDL_Event _event ;
    STATES _states ;
    float _angleRotation ;
    const float _speed ;
    const float _time ;
    float _dt ;



};

#endif // DISPLAY_H
