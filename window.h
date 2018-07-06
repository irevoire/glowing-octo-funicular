#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <SDL.h>

struct window_s {
	SDL_Window *window;
	SDL_Renderer *renderer;

	int width;
	int height;
};

typedef struct window_s* window_t;

extern window_t window;


void create_window(int width, int height);

void destroy_window();

void resize_window();

#endif /* _WINDOW_H_ */
