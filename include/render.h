//
// Created by bapti on 31/10/2025.
//

#pragma once

#include <SDL2/SDL.h>
#include "setting.h"
#include "utils.h"

void Render_graph(SDL_Renderer* renderer, bar** bars, int size);

void Render_setting(SDL_Renderer* renderer, setting *setting);

void Render_frame(SDL_Renderer* renderer, bar** bars, int size);

