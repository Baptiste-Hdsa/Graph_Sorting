//
// Created by bapti on 31/10/2025.
//

#include "render.h"

void Render_graph(SDL_Renderer* renderer, int *array, int size, int width, int height) {
    int bar_width = width / size;
    for (int i = 0; i < size; i++) {
        int bar_height = array[i] * (height / size);
        SDL_FRect rect = {i * bar_width, height - bar_height, bar_width, bar_height};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRectF(renderer, &rect);
    }
}

void Render_setting(SDL_Renderer* renderer, setting* setting) {
    SDL_SetRenderDrawColor(renderer, 75, 74, 74, 255);
    SDL_RenderFillRectF(renderer, &setting->rect);
}