#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <SDL.h>

struct image_s {
	SDL_Surface *surface;
	SDL_Texture *texture;
};

typedef struct image_s *image_t;


image_t create_image(char *path);

void destruct_image(image_t image);

#endif /* _IMAGE_H_ */
