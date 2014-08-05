#ifndef TETRIS_H
#define TETRIS_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "board.h"
#include "collision.h"
#include "draw.h"
#include "fonts.h"
#include "init.h"
#include "input.h"
#include "tetrominoes.h"
#include "types.h"

#define SCREEN_HEIGHT 520
#define SCREEN_WIDTH 430

#define BACKGROUND_R 7 
#define BACKGROUND_G 54 
#define BACKGROUND_B 66

/* background for light theme
#define BACKGROUND_R 253
#define BACKGROUND_G 246 
#define BACKGROUND_B 227 
*/

#define BLOCK_SIZE 24
#define INITIAL_WAIT_TIME 50
#define MIN_MOVE_TIME 4
#define ANIMATE_TIME 10

#define BOARD_START 30
#define BOARD_END (BOARD_START + 10 * BLOCK_SIZE)

#define START_HEIGHT 20
#define END_HEIGHT (START_HEIGHT + 20 * BLOCK_SIZE)

#define NEXT_X (BOARD_END + 45)
#define NEXT_Y (START_HEIGHT + 35)

Game game;
Control input;
Tetromino *tetromino;
Tetromino *next;

void init_game();

#endif
