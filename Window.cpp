#include "Window.h"

#include <stdexcept>

#include "app.h"
#include "util.h"

Window::Window(int width, int height, const char* title)
{
    //set to resizable
  SDLWindow = SDL_CreateWindow(
    title, 
    width, height, SDL_WINDOW_RESIZABLE
  );

  state.width = width;
  state.height = height;
  state.window = SDLWindow;

  if (!SDLWindow) {
    SDL_ShowSimpleMessageBox(
      SDL_MESSAGEBOX_ERROR,
      "Error",
      "Failed to create window",
      nullptr
    );

    cleanup(state);
    throw std::runtime_error("Failed to create window");
  }


}

SDL_Surface* Window::GetSurface() const {
  return SDL_GetWindowSurface(SDLWindow);
}

SDL_Window* Window::GetSDLWindow() const {
  return SDLWindow;
}

Window::~Window() {
  if (SDLWindow && SDL_WasInit(SDL_INIT_VIDEO)) {
    SDL_DestroyWindow(SDLWindow);
  }
}
