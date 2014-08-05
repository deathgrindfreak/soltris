#include "draw.h"


void draw() {
	
	char level[20], score[20];

    /* Blank the screen */
    SDL_FillRect(game.screen, NULL, SDL_MapRGB(game.screen->format, 
                                               BACKGROUND_R,
                                               BACKGROUND_G,
                                               BACKGROUND_B));
    
    /* Draw the background boxes */
    draw_score_next_boxes();

    /* Draw the board */
    draw_board();
    
    /* Draw the fonts */
    draw_string("Next", NEXT_WINDOW_X + 30, NEXT_WINDOW_Y + 5, game.font, false, false);
    draw_string("Score", SCORE_X + 25, SCORE_Y + 5, game.font, false, false);
    draw_string("Level", LEVEL_X + 28, LEVEL_Y + 5, game.font, false, false);
    
    sprintf(level, "%d", game.current_level);
    sprintf(score, "%d", game.current_score);
    draw_string(score, SCORE_X + 55, SCORE_Y + 37, game.font, true, false);
    draw_string(level, LEVEL_X + 55, LEVEL_Y + 37, game.font, true, false);

    /* Draw the tetromino */
    draw_tetromino(next);
    draw_tetromino(tetromino);
    
    /* if the game is paused, draw the paused string */
    if (game.paused)
	    draw_string("Game Paused", game.screen->w / 2, game.screen->h / 2, game.large_font, true, true);

    /* Flip the buffer */
    SDL_Flip(game.screen);

    /* Sleep Briefly */
    SDL_Delay(1);
}


/* delay - set a delay for the CPU (minimum of 60 FPS) */
void delay(unsigned int frame_limit) {
unsigned int ticks = SDL_GetTicks(); 
    if (frame_limit < ticks) {
        return;
    } else if (frame_limit > ticks + 16) {
        SDL_Delay(16);
    } else {
        SDL_Delay(frame_limit - ticks);
    }
}
