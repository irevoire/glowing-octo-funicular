#include "gameloop.h"
#include "window.h"
#include "image.h"
#include "physics.h"

static void handle_window_event(SDL_WindowEventID event)
{
	switch (event)
	{
		case SDL_WINDOWEVENT_RESIZED:
		case SDL_WINDOWEVENT_SIZE_CHANGED:
		case SDL_WINDOWEVENT_MAXIMIZED:
			resize_window();
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

void gameloop(void)
{
	int quit = 0;

	unsigned int time;

	while (!quit)
	{
		time = SDL_GetTicks();

		quit = handle_event();

		/* clear the window */
		SDL_RenderClear(window->renderer);

		collision_update();

		/* update pos and render image in window->renderer */
		update_images();

		if ((time = (SDL_GetTicks() - time)) > 20)
			SDL_Delay(time);

		/* show the window->renderer in the window */
		SDL_RenderPresent(window->renderer);
	}

}
