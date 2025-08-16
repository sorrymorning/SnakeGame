#include <gtest/gtest.h>
#include "../src/brick_game/snake/snake.h"

TEST(SnakeTest, Initialization) {
    Snake snake(5, 5, 3);
    EXPECT_EQ(snake.getBody().size(), 3); // Проверка начальной длины
    EXPECT_EQ(snake.getDirection(), RIGHT); // Направление по умолчанию
}

TEST(SnakeTest, Movement) {
    Snake snake(5, 5, 3);
    snake.move();
    auto body = snake.getBody();
    EXPECT_EQ(body[0], std::make_pair(6, 5)); // Голова сдвинулась вправо
    EXPECT_EQ(body.back(), std::make_pair(5, 6)); // Хвост остался на месте
}

TEST(SnakeTest, Growth) {
    Snake snake(5, 5, 3);
    snake.grow();
    EXPECT_EQ(snake.getBody().size(), 4); // Длина увеличилась
}

TEST(SnakeTest, CollisionWithWall) {
    Snake snake(0, 0, 3); // Голова у (0, 0)
    snake.changeDirection(UP);
    snake.move();
    auto body = snake.getBody();
    EXPECT_TRUE(snake.checkCollision()); // Столкновение с левой стенкой
}

TEST(SnakeTest, DirectionChange) {
    Snake snake(5, 5, 3);
    snake.changeDirection(UP);
    EXPECT_EQ(snake.getDirection(), UP);
    snake.changeDirection(DOWN); // Попытка разворота на 180°
    EXPECT_EQ(snake.getDirection(), UP); // Направление не изменилось
}



