//
// Created by bapti on 31/10/2025.
//

#include "render.h"
#include "utils.h"

void Render_bars(SDL_Renderer* renderer, bar** bars, int size) {
    for (int i = 0; i < size; i++) {
        bars[i]->rect.y = SCREEN_HEIGHT - bars[i]->height;
        bars[i]->rect.x = i * bars[i]->width;
        SDL_SetRenderDrawColor(renderer, bars[i]->color.r, bars[i]->color.g, bars[i]->color.b, bars[i]->color.a);
        SDL_RenderFillRectF(renderer, &bars[i]->rect);
    }
}

void Render_setting(SDL_Renderer* renderer, setting* setting) {
    SDL_SetRenderDrawColor(renderer, 75, 74, 74, 255);
    SDL_RenderFillRectF(renderer, &setting->rect);
}

void Render_frame(SDL_Renderer* renderer, bar** bars, int size) {
    SDL_SetRenderDrawColor(renderer, 42, 41, 40, 255);
    SDL_RenderClear(renderer);

    Render_bars(renderer, bars, size);

    setting* setting = Setting_new();
    Render_setting(renderer, setting);
    free(setting);

    SDL_RenderPresent(renderer);
    //SDL_Delay(10);
}