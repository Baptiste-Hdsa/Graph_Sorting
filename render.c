//
// Created by bapti on 31/10/2025.
//

#include "render.h"

void render_graph(SDL_Renderer* renderer, int *array, int size, int width, int height) {
    int bar_width = width / size;
    for (int i = 0; i < size; i++) {
        int bar_height = array[i] * (height / size);
        SDL_FRect rect = {i * bar_width, height - bar_height, bar_width - 2, bar_height};
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRectF(renderer, &rect);
    }
}