CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS   = board.o collision.o draw.o fonts.o graphics.o init.o input.o tetris.o tetrominoes.o
PROG = tetris
CXX = gcc

# top-level rule to create the program.
all: $(PROG)

# debugging flags
debug: CFLAGS += -O0 -g -DDEBUG
debug: $(PROG)

include Sourcedeps

# compiling other source files.
%.o: %.c %.h  types.h
	$(CXX) $(CFLAGS) -c -s $<

# linking the program.
$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) $(LFLAGS)

# cleaning everything that can be automatically recreated with "make".
clean:
	rm $(PROG) *.o

.PHONY: all clean debug
