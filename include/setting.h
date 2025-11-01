//
// Created by bapti on 01/11/2025.
//

#pragma once

#include "SDL2/SDL.h"

typedef struct setting {
    SDL_FRect rect;

}setting;

setting* Setting_new();
SDL_FRect Rect_setting();