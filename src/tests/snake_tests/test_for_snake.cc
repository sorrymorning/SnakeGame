
#include "game_test.h"

TEST(SnakeGameSnakeTest, Initialization) {
    Snake snake(5, 5, 4);
    SnakeGameTest tester;

    auto body = tester.getSnakeBody(snake);
    EXPECT_EQ(body.size(), 4);
    EXPECT_EQ(body[0], std::make_pair(5, 5));
    EXPECT_EQ(body[3], std::make_pair(5, 8));
    EXPECT_TRUE(snake.isAlive());
    EXPECT_EQ(tester.getSnakeDirection(snake), LEFT);
}

TEST(SnakeGameSnakeTest, MoveWithoutEating) {
    Snake snake(5, 5, 3);
    SnakeGameTest tester;
    tester.setSnakeDirection(snake, LEFT);

    tester.moveSnake(snake, false);
    auto body = tester.getSnakeBody(snake);

    EXPECT_EQ(body.front(), std::make_pair(5, 4)); // голова сместилась влево
    EXPECT_EQ(body.size(), 3);                     // длина не изменилась
}

TEST(SnakeGameSnakeTest, MoveWithEating) {
    Snake snake(5, 5, 3);
    SnakeGameTest tester;

    tester.moveSnake(snake, true);
    auto body = tester.getSnakeBody(snake);

    EXPECT_EQ(body.front(), std::make_pair(5, 4)); // вправо от (5,7)
    EXPECT_EQ(body.size(), 4);                     // длина увеличилась
}

TEST(SnakeGameSnakeTest, ChangeDirectionValid) {
    Snake snake(5, 5, 3);

    snake.changeDirection(Up);
    EXPECT_EQ(snake.getDirection(), UP);

    snake.changeDirection(Left);
    EXPECT_EQ(snake.getDirection(), LEFT);
}

TEST(SnakeGameSnakeTest, ChangeDirectionInvalidOpposite) {
    Snake snake(5, 5, 3);
    SnakeGameTest tester;

    tester.setSnakeDirection(snake, LEFT);
    snake.changeDirection(Right);
    EXPECT_EQ(snake.getDirection(), LEFT) << "Не должен поворачиваться в противоположную сторону";
}

TEST(SnakeGameSnakeTest, CollisionWithWall) {
    Snake snake(0, 0, 3);
    SnakeGameTest tester;
    auto pos = std::make_pair(-1, 0);

    EXPECT_TRUE(tester.checkSnakeCollision(snake, pos));
}

TEST(SnakeGameSnakeTest, CollisionWithBody) {
    Snake snake(5, 5, 4);
    SnakeGameTest tester;

    auto body = tester.getSnakeBody(snake);
    EXPECT_TRUE(tester.checkSnakeCollision(snake, body[1]));
}