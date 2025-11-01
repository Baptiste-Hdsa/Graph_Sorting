#include <SDL2/SDL.h>
#include "utils.h"
#include "render.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "setting.h"


int main() {
    if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) {
        fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    atexit(SDL_Quit);

    SDL_Window* window = SDL_CreateWindow("window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Couldn't initialize window : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Renderer couldn't be created : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_FRect rect = Rect_setting();

    srand(time(NULL));
    bar** bars = Bars_new(SIZE, SCREEN_WIDTH - rect.w, SCREEN_HEIGHT);
    if (!bars) {
        exit(EXIT_FAILURE);
    }
    int quit = false;

    while (!quit) {
        SDL_Event e;

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = true;

            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_q) {
                    Merge_sort(bars, SIZE, renderer);
                }
                if (e.key.keysym.sym == SDLK_s) {
                    Shuffle_bars(bars, SIZE);
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 42, 41, 40, 255);
        SDL_RenderClear(renderer);

        Render_frame(renderer, bars, SIZE);

        setting* setting = Setting_new();
        Render_setting(renderer, setting);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Bars_destroy(bars, SIZE);

    return 0;
}
