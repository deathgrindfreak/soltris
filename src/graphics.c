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
