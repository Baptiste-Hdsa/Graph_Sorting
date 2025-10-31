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

    SDL_Window *window = SDL_CreateWindow("fenêtre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Couldn't initialize window : %s\n", SDL_GetError());
    }
    else
    {
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
        if (!renderer) {
            fprintf(stderr, "Renderer couldn't be created : %s\n", SDL_GetError());
        }
        else
        {

            while (true) {

                SDL_Event  e;
                SDL_WaitEvent(&e);
                if (e.type == SDL_QUIT) {
                    break;
                }

                SDL_SetRenderDrawColor(renderer,  0x00, 0x00, 0x00, 0xFF);

                SDL_RenderClear(renderer);

                for ( int i = 0 ; i < 3 ; i++) {
                    SDL_FRect rect;
                    rect.w = (float)SCREEN_WIDTH / 3;
                    rect.h = SCREEN_HEIGHT;
                    rect.x = (float)i/3 * (float)SCREEN_WIDTH;
                    rect.y = 0;

                    switch (i) {
                    case 0: {
                        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
                        break;
                    }
                    case 1: {
                        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        break;
                    }
                    case 2: {
                        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
                        break;
                    }
                    }
                    SDL_RenderFillRectF(renderer, &rect);
                }
                SDL_RenderPresent(renderer);
            }
            SDL_DestroyRenderer(renderer);
        }
        SDL_DestroyWindow(window);
    }
    SDL_Quit();

    return 0;
}

