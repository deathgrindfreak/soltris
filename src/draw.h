#ifndef DRAW_H
#define DRAW_H

#include "SDL/SDL.h"

#include "fonts.h"
#include "tetris.h"
#include "types.h"
#include "graphics.h"

void draw();
void delay(unsigned int frame_limit);
void swap_animate_colors(bool white);

#endif
