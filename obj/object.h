#ifndef _OBJECT_H_
#define _OBJECT_H_

struct object_s {
	int xs;
	int ys;

	int init_time;
	int time;
};

typedef struct object_s *object_t;

#endif /* _OBJECT_H_ */
