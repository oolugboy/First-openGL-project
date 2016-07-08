/*
 * display.h
 *
 *  Created on: Jun 29, 2016
 *      Author: olujimi
 */

#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>

using namespace std;


class Display
{
    public:
        Display(int height, int width, const string& title);
        virtual ~Display();
        void update();
        bool getClosed();

    protected:
    private:
       // Display(const Display& other){}
      //  Display& operator=(const Display& other){}

        /** This is the pointer to the window that we are about to create **/
        SDL_Window * currWind;
        /** SDL openGL context **/
        SDL_GLContext currContext;
        bool isClosed;

};

#endif // DISPLAY_H



