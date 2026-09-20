#pragma once
#include <SDL3/SDL.h>




struct SDL_State {
    SDL_Window* window;
    SDL_Renderer* renderer;

    int width;
    int height;
    int logWidth;
    int logHeight;

};


extern SDL_State state;