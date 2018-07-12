#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SDL.h>

struct object_s {
	/* SDL_Rect containing x, y, h(eight), w(idth) of the object */
	SDL_Rect *pos;

	/* speed on the x axis*/
	int xs;
	/* speed on the y axis*/
	int ys;

	int init_time;
	int time;
};

typedef struct object_s *object_t;

#endif /* _OBJECT_H_ */
