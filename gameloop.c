#include "window.h"
#include "image.h"

static void handle_window_event(SDL_WindowEventID event)
{
	switch (event)
	{
		case SDL_WINDOWEVENT_RESIZED:
		case SDL_WINDOWEVENT_SIZE_CHANGED:
		case SDL_WINDOWEVENT_MAXIMIZED:
			SDL_GetWindowSize(window->window, &window->width, &window->width);
			break;
		default:
			break;
	}
}

static int handle_event()
{
	SDL_Event event;

	while(SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return 1;
			case SDL_WINDOWEVENT:
				handle_window_event(event.window.event);
				break;
			case SDL_KEYDOWN:
				break;
			default:
				/* "Event not yet implemented */
				break;
		}
	}

	return 0;
}

void gameloop()
{
	int quit = 0;
	int x = 0, y = 0;
	int xs = 1, ys = 1;

	int time;

	image_t image = create_image("balle.bmp");

	while (!quit)
	{
		time = SDL_GetTicks();

		quit = handle_event();

		SDL_RenderClear(window->renderer);

		SDL_Rect dstrect = { x, y, 50, 50};
		SDL_RenderCopy(window->renderer, image->texture, NULL, &dstrect);
		SDL_RenderPresent(window->renderer);

		x = (x + xs);
		y = (y + ys);

		if (x == (window->width - 50) || x == 0)
			xs *= -1;
		if (y == (window->height - 50) || y == 0)
			ys *= -1;

		if ((time = (SDL_GetTicks() - time)) > 20)
			SDL_Delay(time);
	}

}
