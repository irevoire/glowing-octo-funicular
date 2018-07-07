#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <SDL.h>

struct image_s {
	SDL_Surface *surface;
	SDL_Texture *texture;

	SDL_Rect rect;
};

typedef struct image_s *image_t;

struct image_list_s {
	struct image_list_s *next;

	image_t image;

	int (*update)(struct image_list_s *el);

	void *data;
};

typedef struct image_list_s *image_list_t;

extern image_list_t g_all_image;

image_t create_image(const char *const path, int x, int y, int w, int h);

void destruct_image(image_t image);

image_list_t handle_image(image_t image, int(func)(image_list_t));

void update_images(void);

#endif /* _IMAGE_H_ */
