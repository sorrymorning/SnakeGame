

#include "game_test.h"

TEST(SnakeGameAppleTest, EatIncreasesScore) {
  Game game;
  SnakeGameTest tester;

  const int initial_score = 10;
  tester.setGameScore(game, initial_score);
  tester.eatGame(game);

  EXPECT_EQ(tester.getGameScore(game),
            initial_score + 1);
}


TEST(SnakeGameAppleTest, AppleNotOnSnakeBody) {
    Game game;
    SnakeGameTest tester;

    std::vector<std::pair<int, int>> snake_body = {{1, 1}, {2, 2}, {3, 3}};

    tester.generateApple(game, snake_body);
    auto apple_pos = tester.getApplePosition(game);

    for (auto& seg : snake_body) {
        EXPECT_NE(seg, apple_pos) << "Apple spawned on snake body!";
    }
}

TEST(SnakeGameAppleTest, AppleWithinFieldBounds) {
    Game game;
    SnakeGameTest tester;

    std::vector<std::pair<int, int>> snake_body;
    tester.generateApple(game, snake_body);

    auto [x, y] = tester.getApplePosition(game);
    EXPECT_GE(x, 0);
    EXPECT_LT(x, FIELD_H);
    EXPECT_GE(y, 0);
    EXPECT_LT(y, FIELD_W);
}


