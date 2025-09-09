CC = gcc
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

C_SOURCES = gui/cli/fronted.c tetris.c
CPP_SOURCES = brick_game/snake/*.cc
LDFLAGS = -lncurses

TARGET = snake

C_OBJECTS = $(C_SOURCES:.c=.o)
CPP_OBJECTS = $(CPP_SOURCES:.cc=.o)

all: $(TARGET)

$(TARGET): $(C_OBJECTS) $(CPP_OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)  # Добавляем здесь

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
