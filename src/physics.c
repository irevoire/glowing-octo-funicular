#include "physics.h"
#include "object.h"
#include "utils.h"

struct physics_s {
	struct physics_s *next;

	object_t obj;
};

typedef struct physics_s *physics_t;

physics_t g_collision = NULL;

void handle_collision(object_t obj)
{
	if (obj == NULL)
		return;

	physics_t nel = malloc(sizeof(*nel));

	nel->next = g_collision;
	nel->obj = obj;

	g_collision = nel;
}

enum collision_direction {
	NO_COL,
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
	UNKNOW
};

/* TODO Fix this *totaly* shitty function */
static enum collision_direction object_collide(object_t obj1, object_t obj2)
{
	SDL_Rect *rect1 = obj1->pos, *rect2 = obj2->pos;

	if (!(rect1->x < rect2->x + rect2->w &&
			rect1->x + rect1->w > rect2->x &&
			rect1->y < rect2->y + rect2->h &&
			rect1->h + rect1->y > rect2->y))
		return NO_COL;

	if (obj1->xs < obj2->xs && obj2->xs < 0)
		return LEFT;

	if (obj1->xs > obj2->xs && obj2->xs > 0)
		return RIGHT;

	if (obj1->ys < obj2->ys && obj2->ys < 0)
		return BOTTOM;

	if (obj1->ys > obj2->ys && obj2->xs > 0)
		return TOP;

	if (obj1->xs < 0 && obj2->xs > 0)
		return LEFT;

	if (obj1->xs > 0 && obj2->xs < 0)
		return RIGHT;

	if (obj1->ys < 0 && obj2->ys > 0)
		return BOTTOM;

	if (obj1->ys > 0 && obj2->ys < 0)
		return TOP;

	return UNKNOW;
}

void collision_update(void)
{
	physics_t el1, el2;
	enum collision_direction col;

	FOREACH(el1, g_collision)
		FOREACH(el2, el1->next)
		{
			col = object_collide(el1->obj, el2->obj);
			if (col == UNKNOW)
				printf("COLLISION UNKNOW, %d\n", el1->obj->pos->x);
			else if (col == TOP)
				printf("COLLISION UP\n");
			else if (col == BOTTOM)
				printf("COLLISION DOWN\n");
			else if (col == LEFT)
				printf("COLLISION LEFT\n");
			else if (col == RIGHT)
				printf("COLLISION RIGHT, %d\n", el1->obj->pos->x);
		}

}
