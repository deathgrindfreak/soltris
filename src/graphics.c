#include "graphics.h"


/* draw_block - draw a block for a tetromino */
void draw_block(int x, int y, SDL_Color color) {

    /* Surface for drawing the block */
    SDL_Rect block, outline;

    /* Rectangle for block */
    outline.x = x;
    outline.y = y;
    outline.w = outline.h = BLOCK_SIZE;
    block.x = x + 1;
    block.y = y + 1;
    block.w = block.h = BLOCK_SIZE - 2;

    /* Fill the rectangle */
    SDL_FillRect(game.screen, &outline, SDL_MapRGB(game.screen->format, 
                                                   BACKGROUND_R, 
                                                   BACKGROUND_G, 
                                                   BACKGROUND_B));
    SDL_FillRect(game.screen, &block, SDL_MapRGB(game.screen->format, color.r, color.g, color.b));
}


/* draw_tetromino - draws a tetromino to the screen */
void draw_tetromino(Tetromino *tetro) {

    int i;
    for (i = 0; i < 4; i++) {
        draw_block(tetro->x + tetro->coords[i][0] * BLOCK_SIZE, 
                   tetro->y + tetro->coords[i][1] * BLOCK_SIZE, 
                   tetro->color);
    }
}


/* draw_trunc_tetromino - draws a truncated tetromino for the game
   over */
void draw_trunc_tetromino(Tetromino *tetro) {

	int i, test_index;
    for (i = 0; i < 4; i++) {
	    
	    test_index = (tetro->x + tetro->coords[i][0] - BOARD_START) / BLOCK_SIZE;
	    
	    if (tetro->coords[i][1] == get_min_y(tetro) && board[test_index].type == NO_SHAPE) {
			draw_block(tetro->x + tetro->coords[i][0] * BLOCK_SIZE, 
			           tetro->y + (tetro->coords[i][1] + 1) * BLOCK_SIZE, 
					   tetro->color);
	    }
    }
}


/* draw_board - draw the board */
void draw_board() {

    int i;
    for (i = 0; i < 200; i++) {
        draw_block(board[i].x, board[i].y, board[i].color);
    }
}


/* draw_score_next_boxes - draw the boxes that contain the score and
   next tetromino */
void draw_score_next_boxes() {

    /* Surface for drawing the block */
	SDL_Rect level, score, next;

    /* Rectangle for block */
    level.x = LEVEL_X;
    level.y = LEVEL_Y;
    level.w = LEVEL_W; 
	level.h = LEVEL_H;
	
    score.x = SCORE_X;
    score.y = SCORE_Y;
    score.w = SCORE_W; 
	score.h = SCORE_H;
    
    next.x = NEXT_WINDOW_X;
    next.y = NEXT_WINDOW_Y;
    next.w = NEXT_WINDOW_W; 
	next.h = NEXT_WINDOW_H;

    /* Fill the rectangle */
    SDL_FillRect(game.screen, &level, SDL_MapRGB(game.screen->format, 
                                                   colors[0][0], 
                                                   colors[0][1], 
                                                   colors[0][2]));
    
    SDL_FillRect(game.screen, &score, SDL_MapRGB(game.screen->format, 
                                                   colors[0][0], 
                                                   colors[0][1], 
                                                   colors[0][2]));
    
    SDL_FillRect(game.screen, &next, SDL_MapRGB(game.screen->format, 
                                                   colors[0][0], 
                                                   colors[0][1], 
                                                   colors[0][2]));
}


/* draw_menu - draw the game menu */
void draw_menu() {
	draw_string("Game Paused", game.screen->w / 2, game.screen->h / 2 - 100, game.large_font, true, true);
	draw_string("New Game", game.screen->w / 2, game.screen->h / 2 - 50, game.large_font, true, true);
	draw_string("High Scores", game.screen->w / 2, game.screen->h / 2, game.large_font, true, true);
	draw_string("Quit", game.screen->w / 2, game.screen->h / 2 + 50, game.large_font, true, true);
}


/* draw_game_over_menu - draw the game over menu */
void draw_game_over_menu() {
	draw_string("Game Over!", game.screen->w / 2, game.screen->h / 2 - 50, game.large_font, true, true);
	draw_string("New Game?", game.screen->w / 2, game.screen->h / 2, game.font, true, true);
	draw_string("Yes", game.screen->w / 2 - 60, game.screen->h / 2 + 30, game.font, false, true);
	draw_string("No", game.screen->w / 2 + 35, game.screen->h / 2 + 30, game.font, false, true);
}


/* draw_arrow - draw the menu arrow */
void draw_arrow() {
	
	if (game.paused) {
		if (arrow.y == 0) {
			draw_string("->", game.screen->w / 2 - 130, game.screen->h / 2 - 50 + arrow.y, game.large_font, false, true);
		} else if (arrow.y == 50) {
			draw_string("->", game.screen->w / 2 - 150, game.screen->h / 2 - 50 + arrow.y, game.large_font, false, true);
		} else if (arrow.y == 100) {
			draw_string("->", game.screen->w / 2 - 80, game.screen->h / 2 - 50 + arrow.y, game.large_font, false, true);
		} else {
			printf("Invalid arrow value!!!");
		}
	} else if (game.game_over) {
		if (arrow.x == 0) {
			draw_string("->", game.screen->w / 2 - 85, game.screen->h / 2 + 30, game.font, false, true);
		} else if (arrow.x == 1) {
			draw_string("->", game.screen->w / 2 + 10, game.screen->h / 2 + 30, game.font, false, true);
		} else {
			printf("Invalid arrow value!!!");
		}
	}
}
