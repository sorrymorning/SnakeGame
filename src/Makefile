CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
CFLAGS = -Wall -Wextra -O2

C_SOURCES = gui/cli/frontend.c tetris.c
CPP_SOURCES = brick_game/snake/backend.cc \
			  brick_game/snake/game.cc \
			  brick_game/snake/singleton.cc \
			  brick_game/snake/snake.cc \
			  brick_game/snake/timer.cc \
			  brick_game/snake/apple.cc

TET_SOURCES = brick_game/tetris/backend.c

LDFLAGS = -lncurses -lm
	
C_OBJECTS = $(C_SOURCES:.c=.o)
TET_OBJECTS = $(TET_SOURCES:.c=.o)
CPP_OBJECTS = $(CPP_SOURCES:.cc=.o)


snake: $(CPP_OBJECTS) $(C_OBJECTS) 
	$(CXX) $^ -o $@ $(LDFLAGS)  

tetris:$(TET_OBJECTS) $(C_OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o snake tetris gui/cli/*.o brick_game/snake/*.o brick_game/tetris/*.o score.txt
