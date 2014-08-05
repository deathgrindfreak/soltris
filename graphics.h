#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL/SDL.h"

#include "board.h"
#include "tetris.h"

#define LEVEL_X (BOARD_END + 20)
#define LEVEL_Y (START_HEIGHT + 300)
#define LEVEL_W 120
#define LEVEL_H 80

#define SCORE_X (BOARD_END + 20)
#define SCORE_Y (START_HEIGHT + 170)
#define SCORE_W 120
#define SCORE_H 80

#define NEXT_WINDOW_X (BOARD_END + 20)
#define NEXT_WINDOW_Y (START_HEIGHT + 20)
#define NEXT_WINDOW_W 120
#define NEXT_WINDOW_H 100

void draw_block(int x, int y, SDL_Color color);
void draw_tetromino(Tetromino *tetro);
void draw_board();
void draw_score_next_boxes();

#endif
