#pragma once
#include <SDL3/SDL.h>

class Window {
public:
  Window(int width = 800, int height = 600, const char* title = "SDL Window");

  SDL_Surface* GetSurface() const;

  SDL_Window* GetSDLWindow() const;

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  
  ~Window();

private:
  SDL_Window* SDLWindow{nullptr};
};