#include <SDL.h>

#include "image.h"
#include "window.h"
#include "error.h"

image_t create_image(char *path)
{
	image_t image = malloc(sizeof *image);

	image->surface = SDL_LoadBMP(path);
	if (image->surface == NULL)
		handle_SDL_Error("Can't load BMP");

	image->texture = SDL_CreateTextureFromSurface(window->renderer, image->surface);
	if (image->texture == NULL)
		handle_SDL_Error("Can't create surface");

	return image;
}

void destruct_image(image_t image)
{
	SDL_DestroyTexture(image->texture);
	SDL_FreeSurface(image->surface);

	free(image);
}
