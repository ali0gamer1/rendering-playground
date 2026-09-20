#include "util.h"

void cleanup(SDL_State state)
{

SDL_DestroyRenderer(state.renderer);
  SDL_DestroyWindow(state.window);
  
  SDL_Quit();
}
