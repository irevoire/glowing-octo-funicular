#include <SDL.h>

#include "image.h"
#include "window.h"

struct ball_s {
	int xs;
	int ys;
};

typedef struct ball_s *ball_t;

static int update_ball(struct image_list_s *el)
{
	ball_t balls = el->data;

	SDL_Rect *rect = &el->image->rect;

	rect->x += balls->xs;
	rect->y += balls->ys;

	if (rect->x == (window->w - rect->w) || rect->x == 0)
		balls->xs *= -1;
	if (rect->y == (window->h - rect->h) || rect->y == 0)
		balls->ys *= -1;

	return 0;
}

void create_ball()
{
	image_t image = create_image("img/balle.bmp", 0, 0, 50, 50);

	image_list_t el = handle_image(image, update_ball);

	el->data = malloc(sizeof(struct ball_s));

	struct ball_s *balls = el->data;
	balls->xs = 1;
	balls->ys = 1;
}

