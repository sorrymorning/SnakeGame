CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
CFLAGS = -Wall -Wextra -O2

C_SOURCES = gui/cli/frontend.c tetris.c
CPP_SOURCES = brick_game/snake/backend.cc \
			  brick_game/snake/game.cc \
			  brick_game/snake/singleton.cc \
			  brick_game/snake/snake.cc \
			  brick_game/snake/timer.cc 



LDFLAGS = -lncurses

TARGET = snake	

C_OBJECTS = $(C_SOURCES:.c=.o)
CPP_OBJECTS = $(CPP_SOURCES:.cc=.o)

all: $(TARGET)

$(TARGET): $(CPP_OBJECTS) $(C_OBJECTS) 
	$(CXX) $^ -o $@ $(LDFLAGS)  # Добавляем здесь

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET) gui/cli/*.o brick_game/snake/*.o
