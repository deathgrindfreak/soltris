#ifndef FONTS_H
#define FONTS_H

#include "SDL/SDL_ttf.h"

#include "tetris.h"

TTF_Font *load_font(char *name, int size);
void close_font(TTF_Font *font);
void draw_string(char *text, int x, int y, TTF_Font *font, bool center_x, bool center_y);
	
#endif
