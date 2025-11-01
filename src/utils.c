//
// Created by bapti on 01/11/2025.
//

#include <SDL2/SDL.h>
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

bar** Bars_new(int size, int graph_width, int graph_height) {
    bar** bars = calloc(size, sizeof(bar*));
    if (!bars) {
        fprintf(stderr, "Failed to allocated memory for a bars");
        return NULL;
    }

    float bar_width = graph_width / size;

    for (int i = 0; i < size; i++) {
        bars[i] = calloc(1, sizeof(bar));
        if (!bars[i]) {
            fprintf(stderr, "Failed to allocated memory for a bar");
            for (int j = 0; j < i; j++) {
                free(bars[j]);
            }
            free(bars);
            return NULL;
        }
        bars[i]->width = bar_width;
        bars[i]->height = (graph_height / size ) * (i + 1);
        bars[i]->value = i + 1;
        bars[i]->rect = (SDL_FRect){i * bar_width, graph_height - bars[i]->height, bars[i]->width, bars[i]->height};
        bars[i]->color = (SDL_Color){0xFF, 0xFF, 0xFF, 0xFF};
    }
    return bars;
}

void Bars_destroy(bar** bars, int size) {
    for (int i = 0; i < size; i++) {
        free(bars[i]);
    }
    free(bars);
}

void Shuffle_bars(bar** bars, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i+1);

        bar* temp = bars[i];
        float tempx = bars[i]->rect.x;
        float tempy = bars[i]->rect.y;

        float jtempx = bars[j]->rect.x;
        float jtempy = bars[j]->rect.y;

        bars[i] = bars[j];
        bars[i]->rect.x = tempx;
        bars[i]->rect.y = tempy;

        bars[j] = temp;
        bars[j]->rect.x = jtempx;
        bars[j]->rect.y = jtempy;

    }
}


