#include <SDL.h>

#include "image.h"
#include "window.h"
#include "utils.h"

image_list_t g_all_image = NULL;

image_t create_image(const char *const path, int x, int y, int w, int h)
{
	image_t image = malloc(sizeof *image);

	image->surface = SDL_LoadBMP(path);
	if (image->surface == NULL)
		handle_SDL_Error("Can't load BMP");

	image->texture = SDL_CreateTextureFromSurface(window->renderer,
			image->surface);
	if (image->texture == NULL)
		handle_SDL_Error("Can't create surface");

	image->rect.x = x;
	image->rect.y = y;

	image->rect.w = w == -1 ? image->surface->w : w;
	image->rect.h = h == -1 ? image->surface->h : h;

	return image;
}

void destruct_image(image_t image)
{
	SDL_DestroyTexture(image->texture);
	SDL_FreeSurface(image->surface);

	free(image);
}

image_list_t handle_image(image_t image, int(*func)(image_list_t))
{
	image_list_t el = malloc(sizeof(*el));

	el->next = g_all_image;

	el->image = image;
	el->update = func;

	g_all_image = el;

	return el;
}

void update_images()
{
	image_list_t el;
	FOREACH(el, g_all_image)
	{
		el->update(el);
		SDL_RenderCopy(window->renderer, el->image->texture,
				NULL, &el->image->rect);
	}
}
