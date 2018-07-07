# Directory
SRC_DIR = ./src
INC_DIR = $(PWD)/include

# Sources
CSOURCES = $(shell find . -type f -iname '*.c')
HSOURCES = $(wildcard $(INC_DIR)/*.h)

# Objects
COBJ = $(CSOURCES:.c=.o)


CC = gcc


CFLAGS := $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)


# Include directories
CFLAGS += -I$(INC_DIR)


all: platformer

platformer: $(COBJ)
	$(CC) $(LDFLAGS) $^ -o platformer

%.o: %.c $(HSOURCES)
	$(CC) $(CFLAGS) -c $< -o $@ 


clean:
	rm -f platformer
	rm -f $(COBJ)
