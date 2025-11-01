//
// Created by bapti on 31/10/2025.
//

#pragma once

#include <SDL2/SDL.h>
#include "setting.h"

void Render_graph(SDL_Renderer* renderer, int *array, int size, int width, int height);

void Render_setting(SDL_Renderer* renderer, setting *setting);

