//
// Created by bapti on 01/11/2025.
//

#pragma once

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define SIZE 50


typedef struct bar {
    int height, width;
    int value;
    SDL_FRect rect;
    SDL_Color color;
}bar;


bar** Bars_new(int size, int graph_width, int graph_height);
void Bars_destroy(bar** bars, int size);

void Shuffle_bars(bar** bars, int size);


