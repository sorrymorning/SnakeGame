CC = g++
CFLAGS = -std=c++20	 -Wall -Wextra -Werror -pedantic
LDFLAGS = -lgtest -lgtest_main -lpthread
LIB_NAME = s21_snake.a
SNAKE_PATH = src/brick_game/snake
TEST_SRC := tests/s21_test_main.cc tests/s21_test_snake.cc
TEST_NAME = s21_test
SRCS := $(SNAKE_PATH)/game.cc \
		$(SNAKE_PATH)/snake.cc


OBJS := $(SRCS:.cc=.o)


test: $(TEST_NAME)
	./$(TEST_NAME)

$(TEST_NAME): $(TEST_SRC) $(LIB_NAME)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)




$(LIB_NAME):$(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)
	ranlib $@
	rm -f $(OBJS)



%.o: %.cc
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(LIB_NAME) $(TEST_NAME)