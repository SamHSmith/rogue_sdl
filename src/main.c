#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
//#include "game.h"
#include "player.h"

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
    { return 1; }
    printf("SDL initialized.\n");

    bool fullscreen = false;
    if(fullscreen)
    {
        int flags = 0;
        flags = SDL_WINDOW_FULLSCREEN;
    }
    SDL_Window* window = SDL_CreateWindow(
                            "Woods",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            640, 640,
                            SDL_WINDOW_RESIZABLE
    );
    if(!window)
    { printf("Failed to create window\n"); return 2; }
    printf("Window Created.\n");

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
    { printf("Failed to create renderer\n"); return 3; }
    printf("Renderer Created.\n");

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    int cnt = 0;
    Player player;
    player.xpos = 0;
	player.ypos = 0;
    player_init(renderer, &player);
    const int FPS = 60;
    const int frame_delay = 1000/FPS;
    Uint32 time_start;
    int frame_time;
    bool running = true;
    while(running)
    {
        { // Input
            SDL_Event event;
            SDL_PollEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }

        cnt++;
        player.xpos++;
        time_start = SDL_GetTicks();

        { // Update
            printf("%d\n", cnt);
            player_update(&player);
        }

        { // Render
            SDL_RenderClear(renderer);
            player_draw(renderer, &player);
            SDL_RenderPresent(renderer);
        }


        frame_time = SDL_GetTicks() - time_start;
        if(frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    // Cleanup
    SDL_DestroyTexture(player.player_tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("SDL Quit.\n");
	return 0;
}
