#include <stdlib.h>

/* Framworks */
#include <SDL.h>

/* Local */
#include "window.h"
#include "gameloop.h"

int main(int argc, char **argv)
{
	create_window(640, 480);

	gameloop();

	destroy_window();

	SDL_Quit();

	return 0;
}

