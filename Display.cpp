#include "Display.h"

///INITIALIZING THE PRIVATE VARIABLES
Display::Display() :
            _window(nullptr),
            _windowName(" "),
            _width(0), _height(0),
            _states(STATES :: KEEP),
            _angleRotation(0.0f),
            _speed(10.0f),
            _time(10.0f),
            _dt(1.0f)
{
    initDisplay() ; /// calling the function that initializes the SDL
}

/// INITIALIZING THE SDL ELEMENTS
 void Display:: initDisplay(){
    /// The name of the window
    _windowName = "IMMEDIATE MODE" ;
    /// The width of the window
    _width = 500 ;
    /// The height of the window
    _height = _width ;

    ///Initialize SDL, but removing it does change anything
    SDL_Init(SDL_INIT_EVERYTHING) ;

    /// Creating the window and passing it to the pointer
    _window = SDL_CreateWindow( _windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL) ;

    ///TEST
    if (_window == nullptr) {
        errorMessage("SDL") ;
    }
    /// Creating the context assotiated with the window
    SDL_GLContext context = SDL_GL_CreateContext(_window) ;

    ///TEST
    if (context == nullptr) {
        errorMessage("CONTEXT") ;
    }

    ///Create a double buffered window
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1) ;

    /// GLEW
    GLenum status = glewInit() ;

    /// TEST
    if (status != GLEW_OK) {
        errorMessage("GLEW") ;
    }

 }

///
 void Display::DisplayWindow() {

    /// Finding errors
    GLenum error = glGetError() ;

   ///TEST
    if (error != GL_NO_ERROR ) {
      errorMessage("OPENGL") ;

    }
    /// GAME LOOP
    while (_states == STATES :: KEEP) {
        draw() ; /// triangles maker function
        eventHandler() ; /// QUIT handler function, if the close buttomif cliked the _state ==  STATES :: QUIT
    }
 }


/// HANDLING THE CLOSE BUTTON
 void Display::eventHandler() {
    /// TO ENTER THE LOOP AN EVENT MUST OCCUR
    while (SDL_PollEvent(&_event) ) { /// RECEIVES THE SYS EVENTS

        /// if an event is of type
        switch (_event.type) {
        /// click on the close buttom
            case SDL_QUIT :
                _states = STATES :: QUIT ;
                /// then change the state, which will break the game loop
                /// and break the eventhandler loop too
            break ;
        }
    }
 }

 void Display::draw(){

    /// Clear the screen with black color and no transparenty, commeting it, will give the same result
    glClearColor(0.0f,0.0f,0.0f,0.250f) ;
    /// what it does ?
    glClearDepth(1.0) ;
    /// Something with fragment shades ?
    /// when i remve it the red triangles disapears
    glEnable(GL_DEPTH_TEST) ;
    /// Clear the buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    /// the function that rotate the triangles
    rotation()  ;
    /// the function that use the immediate mode drawing function
    immediateMode() ;
    /// Swap the buffer and draw eveerything to the screen
    SDL_GL_SwapWindow(_window) ;

 }


void Display::immediateMode() {


    /// Enabling rotation
    glRotatef(_angleRotation,0.50f,_dt,0.25f) ;
    /// Enabling triangles
    glBegin(GL_TRIANGLES) ;

    /// CREATING THE TRIANGLES

    /// RED
    glColor3f(1.0f,0.0f,0.0f) ;
    glVertex3f(0.5f,0.0f,0.0f) ;

    glColor3f(1.0f,0.0f,0.0f) ;
    glVertex3f(-0.5f,-0.5f,0.5f) ;

    glColor3f(1.0f,0.0f,0.0f) ;
    glVertex3f(0.0f,0.0f,0.0f) ;


    ///GREEN
    glColor3f(0.0f,1.0f,0.0f) ;
    glVertex3f(0.5f,0.0f,0.0f) ;

    glColor3f(0.0f,1.0f,0.00f) ;
    glVertex3f(0.0f,0.5f,0.0f) ;

    glColor3f(0.0f,1.0f,0.0f) ;
    glVertex3f(-0.5f,-0.5f,0.5f) ;

    ///BLUE
    glColor3f(0.0f,0.0f,1.0f) ;
    glVertex3f(0.5f,0.0f,0.0f) ;

    glColor3f(0.0f,0.0f,1.0f) ;
    glVertex3f(0.0f,0.5f,0.0f) ;

    glColor3f(0.0f,0.0f,1.0f) ;
    glVertex3f(0.0f,0.0f,0.0f) ;

    ///ORANGE
    glColor3f(1.0f,0.5f,0.0f) ;
    glVertex3f(0.0f,0.0f,0.0f) ;

    glColor3f(1.0f,0.5f,0.0f) ;
    glVertex3f(0.0f,0.5f,0.0f) ;

    glColor3f(1.0f,0.5f,0.0f) ;
    glVertex3f(-0.5f,-0.5f,0.5f) ;



    glEnd() ;

}

/// THE FUNCTION THAT SETS THE ANGLE OF ROTATION
void Display :: rotation() {

        /// the rotation's angle
     _angleRotation += _speed*_time*_dt*_dt ;
     _dt *= 0.125;
     if (_angleRotation > 50.0f) {
        _angleRotation = 0  ;

     }
}

/// DESTRUCTOR
Display::~Display(){

    /// Destroying the window
    SDL_DestroyWindow(_window) ;
    /// QUITING SDL
    SDL_Quit() ;

    std :: cout << _window << "GOOD BYE" << std :: endl ;
}


/// The error function
void Display::errorMessage(std :: string errorType) {

    std :: cout << errorType + " was unable to open" << std :: endl ;
    SDL_Quit() ;
}
