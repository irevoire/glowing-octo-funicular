CFLAGS = $(shell sdl2-config --cflags)
LD_LIBS = $(shell sdl2-config --libs)


all: platformer

platformer: platformer.o gameloop.o image.o window.o ball.o
	$(CC) $(LD_LIBS) $^ -o platformer

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f platformer
	rm -f *.o
