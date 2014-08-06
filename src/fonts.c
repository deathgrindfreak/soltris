#include "fonts.h"


/* load_font - loads a font */
TTF_Font *load_font(char *name, int size) {

	/* Open the font */
	TTF_Font *font = TTF_OpenFont(name, size);

	if (font == NULL) {
		printf("Failed to open font %s: %s\n", name, TTF_GetError());
		
		exit(1);
	}
	
	return font;
}


/* close_font - closes a font */
void close_font(TTF_Font *font) {

	/* close the font if once we're done with it */
	if (font != NULL) {
		TTF_CloseFont(font);
	}
}


/* draw_string - draws a string on the screen */
void draw_string(char *text, int x, int y, TTF_Font *font, bool center_x, bool center_y) {

	SDL_Rect dest;
	SDL_Surface *surface;
	SDL_Color foreground_color, background_color;

	foreground_color.r = 238;
	foreground_color.g = 232;
	foreground_color.b = 213;
		
	background_color.r = 0;
	background_color.g = 0;
	background_color.b = 0;
	
	/* create the destination surface */
	surface = TTF_RenderUTF8_Shaded(font, text, foreground_color, background_color);
	
	/* Set the color key */
	SDL_SetColorKey(surface, (SDL_SRCCOLORKEY|SDL_RLEACCEL), SDL_MapRGB(surface->format, 0, 0, 0));
	
	if (surface == NULL) {
		printf("Couldn't create string %s: %s\n", text, SDL_GetError());

		exit(1);
	}
	
	/* create the destination rectangle */
	if (center_x) {
		dest.x = x + 5 - surface->w / 2;
	} else {
		dest.x = x;
	}
	
	if (center_y) {
		dest.y = y + 5 - surface->h / 2;
	} else {
		dest.y = y;
	}
	
	dest.w = surface->w;
	dest.h = surface->h;
	
	SDL_BlitSurface(surface, NULL, game.screen, &dest);
	
	/* Free the temporary surface */
	SDL_FreeSurface(surface);
}
