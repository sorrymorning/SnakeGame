# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Имена исходных файлов
SRCS = main.cc game.cc snake.cc timer.cc
OBJS = $(SRCS:.cc=.o)
TARGET = snake_game

# Цель по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	./$(TARGET)

# Компиляция отдельных .cc файлов
main.o: main.cc game.h
	$(CXX) $(CXXFLAGS) -c main.cc

game.o: game.cc game.h snake.h api.h
	$(CXX) $(CXXFLAGS) -c game.cc

snake.o: snake.cc snake.h
	$(CXX) $(CXXFLAGS) -c snake.cc

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)