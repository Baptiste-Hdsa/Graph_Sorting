#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main() {

    /* Initialize defaults, Video and Audio */
    if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)==-1)) {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    atexit(SDL_Quit);

    SDL_Window *window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Couldn't initialize window : %s\n", SDL_GetError());
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        fprintf(stderr, "Renderer couldn't be created : %s\n", SDL_GetError());
    }

    SDL_FRect rect;
    rect.w = (float)1/5 * SCREEN_WIDTH;
    rect.h = SCREEN_HEIGHT;
    rect.x = (float)4/5 * (float)SCREEN_WIDTH;
    rect.y = 0;

    int quit = false;

    while (!quit) {

        SDL_Event e;
        SDL_WaitEvent(&e);
        if(e.type == SDL_QUIT) quit = true;

        SDL_SetRenderDrawColor(renderer, 42, 41, 40, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 75, 74, 74, 255);
        SDL_RenderFillRectF(renderer, &rect);
        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}