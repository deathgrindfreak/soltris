#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

typedef enum {
    NO_SHAPE,
    LINE,
    SQUARE,
    T_SHAPE,
    J_SHAPE,
    L_SHAPE,
    S_SHAPE,
    Z_SHAPE
} tetromino_t;

typedef struct Game {
	
	struct RBG {
		Uint8 r, g, b;
	} animate_colors[40];
	
    int current_wait_time;
    int current_score;
	int current_level;
	int remove_rows[20];
	int animate_time;
	int animate_times;
	int num_animation_rows;
    bool game_over;
    bool paused;
	bool animate, remove;
    SDL_Surface *screen;
	TTF_Font *font;
	TTF_Font *large_font;
} Game;

typedef struct Control {
    bool up, down, left, right;
} Control;

typedef struct Tetromino {
    int x, y, h, w;
    int wait_time, move_time;
	int offset_x, offset_y;
    int coords[4][2];
    tetromino_t type;
    SDL_Color color;
} Tetromino;

typedef struct Blocks {
    int x, y;
    SDL_Color color;
    tetromino_t type;
} Blocks;

#endif
