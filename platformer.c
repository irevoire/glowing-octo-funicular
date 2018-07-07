#include <stdlib.h>

/* Framworks */
#include <SDL.h>

/* Local */
#include "window.h"
#include "gameloop.h"

int main(int argc, char **argv)
{
	create_window(640, 480);

#include "obj/ball/ball.h"
	create_moving_ball(12, 1, 1);

	create_moving_ball(1, -3, 1);
	
	gameloop();

	destroy_window();

	SDL_Quit();

	return 0;
}

