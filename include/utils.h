#define handle_SDL_Error(s) \
	do { \
		SDL_Log("%s: %s", (s), SDL_GetError()); \
		exit(EXIT_FAILURE); \
	} while (0);

#define FOREACH(el, base) \
	for ((el) = (base); (el) != NULL; (el) = (el)->next)
