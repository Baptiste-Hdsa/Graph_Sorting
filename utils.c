//
// Created by bapti on 01/11/2025.
//

#include <SDL2/SDL.h>
#include "utils.h"

int* Create_array(int size) {

    int *array = calloc(1, size * sizeof(int));
    if (!array)
        fprintf(stderr, "Failed to allocate memory");

    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
    return array;
}

void Shuffle_array(int *array, int size) {

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}