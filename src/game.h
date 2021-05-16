#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "player.h"

void init(SDL_Window* window, SDL_Renderer* renderer, const char* title, int width, int height, int x, int y, bool fullscreen, bool *running);
void handle_events(SDL_Window* window, SDL_Renderer* renderer, bool *running);
void update(int cnt, Player* player);
void render(SDL_Renderer* renderer, Player* player);
void clean_sdl(SDL_Window* window, SDL_Renderer* renderer, Player* player);

#endif // GAME_H
