//
// Created by bapti on 31/10/2025.
//

#include <SDL2/SDL.h> // Pour SDL_Renderer
#include "sorting.h"
#include "render.h"  // Pour Render_graph

static void Merge(int *array, int *temp_array, int left, int mid, int right, SDL_Renderer* renderer, int size, int render_width, int render_height);

static void Merge_sort_recursive(int *array, int *temp_array, int left, int right, SDL_Renderer* renderer, int size, int render_width, int render_height);

static void Merge(int *array, int *temp_array, int left, int mid, int right, SDL_Renderer* renderer, int size, int render_width, int render_height) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j]) {
            temp_array[k++] = array[i++];
        } else {
            temp_array[k++] = array[j++];
        }
    }

    while (i <= mid) {
        temp_array[k++] = array[i++];
    }
    while (j <= right) {
        temp_array[k++] = array[j++];
    }

    for (i = left; i <=right; i++) {
        array[i] = temp_array[i];

        SDL_SetRenderDrawColor(renderer, 42, 41, 40, 255);
        SDL_RenderClear(renderer);

        Render_graph(renderer, array, size, render_width, render_height);

        SDL_RenderPresent(renderer);
        //SDL_Delay(10);
    }
}

static void Merge_sort_recursive(int *array, int *temp_array, int left, int right, SDL_Renderer* renderer, int size, int render_width, int render_height) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        Merge_sort_recursive(array, temp_array, left, mid, renderer, size, render_width, render_height);
        Merge_sort_recursive(array, temp_array, mid + 1, right, renderer, size, render_width, render_height);

        Merge(array, temp_array, left, mid, right, renderer, size, render_width, render_height);
    }
}

void Merge_sort(int *array, int size, SDL_Renderer* renderer, int render_width, int render_height) {
    if (size<2) {
        return;
    }
    int *temp_array = calloc(1, size * sizeof(int));
    if (!temp_array) {
        fprintf(stderr, "Failed to allocate memory for temp_array");
        return;
    }
    Merge_sort_recursive(array, temp_array, 0, size - 1, renderer, size, render_width, render_height);

    free(temp_array);
}