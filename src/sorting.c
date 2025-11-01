//
// Created by bapti on 31/10/2025.
//

#include <SDL2/SDL.h>
#include "sorting.h"
#include "render.h"
#include "utils.h"

static void Merge(bar** bars, bar** temp_bars, int left, int mid, int right, SDL_Renderer* renderer, int size);

static void Merge_sort_recursive(bar** bars, bar** temp_bars, int left, int right, SDL_Renderer* renderer, int size);


static void Merge(bar** bars, bar** temp_bars, int left, int mid, int right, SDL_Renderer* renderer, int size) {
    int i = left;
    int j = mid + 1;
    int k = left;
    
    
    while (i <= mid && j <= right) {
        
        bars[i]->color = (SDL_Color){255, 0, 0, 255};
        bars[j]->color = (SDL_Color){255, 0, 0, 255};
        Render_frame(renderer, bars, size);
        
        if (bars[i]->value <= bars[j]->value) {
            temp_bars[k++] = bars[i++];
        } else {
            temp_bars[k++] = bars[j++];
        }
        
        if (i <= mid) bars[i]->color = (SDL_Color){255, 255, 255, 255};
        if (j <= right) bars[j]->color = (SDL_Color){255, 255, 255, 255};
    }
    
    while (i <= mid) {
        temp_bars[k++] = bars[i++];
    }
    while (j <= right) {
        temp_bars[k++] = bars[j++];
    }

    for (i = left; i <=right; i++) {
        bars[i] = temp_bars[i];
        bars[i]->color = (SDL_Color){0, 255, 0, 255};
        Render_frame(renderer, bars, size);
        bars[i]->color = (SDL_Color){255, 255, 255, 255};
       
    }
}

static void Merge_sort_recursive(bar** bars, bar** temp_bars, int left, int right, SDL_Renderer* renderer, int size) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        Merge_sort_recursive(bars, temp_bars, left, mid, renderer, size);
        Merge_sort_recursive(bars, temp_bars, mid + 1, right, renderer, size);

        Merge(bars, temp_bars, left, mid, right, renderer, size);
    }
}

void Merge_sort(bar** bars, int size, SDL_Renderer* renderer) {
    if (size<2) {
        return;
    }
    bar** temp_bars = calloc(1, size * sizeof(bar*));
    if (!temp_bars) {
        fprintf(stderr, "Failed to allocate memory for temp_bars");
        return;
    }
    Merge_sort_recursive(bars, temp_bars, 0, size - 1, renderer, size);

    free(temp_bars);
}