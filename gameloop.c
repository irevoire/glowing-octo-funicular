#include "window.h"
#include "image.h"

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

void gameloop()
{
	int quit = 0;

	int time;

#include "ball.h"
	create_ball();

	while (!quit)
	{
		time = SDL_GetTicks();

		quit = handle_event();

		SDL_RenderClear(window->renderer);

		/* update pos and render image in window->renderer */
		update_images();

		SDL_RenderPresent(window->renderer);

		if ((time = (SDL_GetTicks() - time)) > 20)
			SDL_Delay(time);
	}

}
