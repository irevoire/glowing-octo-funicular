# Directory
SRC_DIR := src
INC_DIR := include

# Sources
CSOURCES := $(shell find . -type f -iname '*.c')
HSOURCES := $(wildcard $(INC_DIR)/*.h)

# Objects
COBJ := $(CSOURCES:.c=.o)

CC := gcc

WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wconversion -Wstrict-prototypes -Werror
CFLAGS := -g -std=gnu99 $(WARNINGS)

# SLD2
CFLAGS += $(shell sdl2-config --cflags)
LDFLAGS := $(shell sdl2-config --libs)

# Include directories
CFLAGS += -I$(INC_DIR)

EXE := platformer

.PHONY: all clean

all: $(EXE)

$(EXE): $(COBJ)
	@$(CC) $(LDFLAGS) $^ -o $(EXE)

%.o: %.c $(HSOURCES)
	@$(CC) $(CFLAGS) -c $< -o $@ 


clean:
	-@$(RM) $(EXE)
	-@$(RM) $(COBJ)
