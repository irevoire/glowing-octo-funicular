#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <SDL.h>

struct object_s {
	SDL_Rect *pos;

	int xs;
	int ys;

	int init_time;
	int time;
};

typedef struct object_s *object_t;

#endif /* _OBJECT_H_ */
