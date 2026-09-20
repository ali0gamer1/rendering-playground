#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

#include <SDL3_image/SDL_image.h>

#include "app.h"
#include "Window.h"
#include "util.h"
#include "renderer.h"

bool IsRunning = true;

void HandleEvent(SDL_Event& E);
void init();


int main(int, char**) {
    


    init(); 


    SDL_Texture *idleTex = IMG_LoadTexture(state.renderer, "static/idle.png");

    const bool *keys = SDL_GetKeyboardState(nullptr);

    float playerX = 0.0f, playerY = 0.0f;
    const float floorY = state.logHeight;


    SDL_SetTextureScaleMode(idleTex, SDL_ScaleMode::SDL_SCALEMODE_NEAREST);

    SDL_Event Event;
    
    uint64_t lastTime = SDL_GetTicks();

    bool flipH = false;

    while (IsRunning) {
        uint64_t nowTime = SDL_GetTicks();

        float deltaTime = (nowTime - lastTime) / 1000.0f;

        while (SDL_PollEvent(&Event)) {

        HandleEvent(Event);

        
        }


        float moveAmount = 0;
        if (keys[SDL_SCANCODE_A]) {
            moveAmount -= 250.0f;
            flipH = true;
        }
        if (keys[SDL_SCANCODE_D]) {
            moveAmount += 250.0f;
            flipH = false;
        }

        playerX += moveAmount * deltaTime;

        SDL_SetRenderDrawColor(state.renderer, 0, 222, 0, 255);
        SDL_RenderClear(state.renderer);

        SDL_FRect src{
            
        .x = 0, .y = 0, .w = 32, .h = 32
        };

        SDL_FRect dst{
        .x = playerX, .y = floorY - 32, .w = 32, .h = 32
        };

        //SDL_RenderTexture(state.renderer, idleTex, &src, &dst);

        SDL_RenderTextureRotated(state.renderer, idleTex, &src, &dst, 0.0f, nullptr, flipH ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        SDL_RenderPresent(state.renderer);

        


        lastTime = nowTime;
    }

    SDL_DestroyTexture(idleTex);
    cleanup(state);
    return 0;

}
//copilot are you there? -> ja ich bin da.



void HandleEvent(SDL_Event& E) {
  if (E.type == SDL_EVENT_MOUSE_MOTION) {
    std::cout << "Mouse moved\n";
  } else if (E.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
    std::cout << "Mouse clicked\n";
  } else if (E.type == SDL_EVENT_KEY_DOWN) {
    std::cout << "Keyboard button pressed\n";
  } else if (E.type == SDL_EVENT_QUIT) {
    IsRunning = false;
  }
}


void init() {

    SDL_Init(SDL_INIT_VIDEO);

    Window *GameWindow = new Window(1600, 900, "SDL Window");

    Renderer *GameRenderer = new Renderer();


    

    int logWidth = 640, logHeight = 320;

    state.logWidth = logWidth;
    state.logHeight = logHeight;
    SDL_SetRenderLogicalPresentation(state.renderer, logWidth, logHeight, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    

}