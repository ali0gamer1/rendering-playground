#include "renderer.h"

Renderer::Renderer()
{
    renderer = SDL_CreateRenderer(state.window, nullptr);

    if(!renderer)
    {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            "Failed to create renderer",
            nullptr
        );

        

        cleanup(state);
        throw std::runtime_error("Failed to create renderer");
    }
    state.renderer = renderer;
}

