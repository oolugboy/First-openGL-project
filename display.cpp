/*
 * display.cpp

 *
 *  Created on: Jun 29, 2016
 *      Author: olujimi
 */
#include "display.h"
#include <iostream>
using namespace std;
/** We are using SDL2 to create the window **/

/** need arguments to specify the dimensions of the window **/
Display::Display(int height, int width, const string & title)
{
    /** Okay we initialize SDL **/
    SDL_Init(SDL_INIT_EVERYTHING);
    /** Because we are doing SDL using OpenGL, we can use some additional parameters **/
    /** firstly to be able to get all the possible colors we need **/
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    /** This specifies how transparent the colors will be **/
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    /** Now to set the buffer size for every pixel **/
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);/** 32 because we need all the color data for each pixel **/
    /** allocate space for the second buffer **/
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    /** Now to initialize our window **/
    currWind = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

    /** Now to create the context **/
    currContext = SDL_GL_CreateContext(currWind);

    /** Now to use the openGL library **/
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        cerr << " Glew did not initialize " << endl;
    }
    isClosed = false;
}
Display::~Display()
{
    /** Then we are deallocating everything **/
    /** firstly we deallocate the context **/
    SDL_GL_DeleteContext(currContext);
    /** We then deallocate the window **/
    SDL_DestroyWindow(currWind);

    SDL_Quit();
    //dtor
}
void Display::update()
{
    SDL_GL_SwapWindow(currWind);

    /** receive and handle all the events that the operating system throws **/
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            isClosed = true;
        }
    }
}
bool Display::getClosed()
{
    return isClosed;
}



