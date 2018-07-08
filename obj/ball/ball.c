#include <SDL.h>

#include "ball.h"
#include "object.h"

#include "image.h"
#include "window.h"

static int update_ball(struct image_list_s *el)
{
	object_t balls = el->data;

	if (balls->time-- > 0)
		return 0;

	balls->time = balls->init_time;

	SDL_Rect *rect = &el->image->rect;

	rect->x += balls->xs;
	rect->y += balls->ys;

	if (rect->x >= (window->w - rect->w) || rect->x <= 0)
		balls->xs *= -1;
	if (rect->y >= (window->h - rect->h) || rect->y <= 0)
		balls->ys *= -1;

	return 0;
}

static image_list_t create_ball()
{
	image_t image = create_image("media/balle.bmp", window->w / 2, window->h / 2, 50, 50);

	return handle_image(image, update_ball);
}

void create_moving_ball(int xs, int ys, int time)
{
	image_list_t el = create_ball();

	el->data = malloc(sizeof(struct object_s));

	object_t balls = el->data;
	balls->xs = xs;
	balls->ys = ys;
	balls->init_time = time;
	balls->time = time;
}

