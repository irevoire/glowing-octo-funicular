/* Framworks */
#include <SDL.h>

#include "window.h"
#include "utils.h"

window_t window = NULL;

void create_window(int width, int height)
{
	window = malloc (sizeof *window);
	if (SDL_Init(SDL_INIT_VIDEO))
		handle_SDL_Error("Unable to initialize SDL");

	window->window = SDL_CreateWindow("Shitty game",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_RESIZABLE);
	if (window->window == NULL)
		handle_SDL_Error("Could not create window");

	window->renderer = SDL_CreateRenderer(window->window, -1,
			SDL_RENDERER_ACCELERATED |
			SDL_RENDERER_PRESENTVSYNC |
			SDL_RENDERER_TARGETTEXTURE);
	if (window->renderer == NULL)
		handle_SDL_Error("Could not create render");

	window->w= width;
	window->h= height;
}

void destroy_window()
{
	SDL_DestroyRenderer(window->renderer);
	SDL_DestroyWindow(window->window);

	free(window);
}

void resize_window()
{
	SDL_GetWindowSize(window->window, &window->w, &window->h);
}
