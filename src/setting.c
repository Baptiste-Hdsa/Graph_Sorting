//
// Created by bapti on 01/11/2025.
//

#include <SDL_rect.h>
#include "utils.h"
#include "setting.h"

SDL_FRect Rect_setting() {
    SDL_FRect rect;
    rect.w = (float)1 / 5 * SCREEN_WIDTH;
    rect.h = SCREEN_HEIGHT;
    rect.x = (float)4 / 5 * (float)SCREEN_WIDTH;
    rect.y = 0;
    return rect;
}

setting* Setting_new() {
    setting* set = calloc(1, sizeof(setting));
    if (!set) {
        fprintf(stderr, "Failed to allocate memory for setting : %s/n" , SDL_GetError());
        return NULL;
    }
    set->rect = Rect_setting();
    return set;
}
