CFLAGS = `sdl2-config --cflags`
LD_LIBS = `sdl2-config --libs`


all: platformer

platformer: platformer.o gameloop.o image.o window.o
	$(CC) $(LD_LIBS) $^ -o platformer

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f platformer
	rm -f *.o
