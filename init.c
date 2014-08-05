#include "init.h"


/* init - Initialize SDL video, audio and ttf */
void init(char *title) {

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {

        printf("Failed to initialize SDL: %s\n", SDL_GetError());

        exit(1);
    }

    /* Initialize SDL_ttf */
    if (TTF_Init() < 0) {

        printf("Failed to initialize SDL TTF: %s\n", SDL_GetError());

        exit(1);
    }

    /* Open the game screen */
    game.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE | SDL_DOUBLEBUF);

    if (game.screen == NULL) {

        printf("Failed to set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());

        exit(1);
    }

    /* Open the mixer */
    if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0) {

        printf("Failed to initialize audio: %s\n", Mix_GetError());

        exit(1);
    }

    /* Set the caption */
    SDL_WM_SetCaption(title, NULL);
}


/* cleanup - Free all SDL objects at exit */
void cleanup() {
	
	free(tetromino);
	free(next);

    /* Free the game surface */
    SDL_FreeSurface(game.screen);

    /* Close the mixer */
    Mix_CloseAudio();

    /* Close SDL_TTF */
    TTF_Quit();

    /* Close SDL */
    SDL_Quit();
}
