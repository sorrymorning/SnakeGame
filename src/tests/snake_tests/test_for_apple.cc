
#include <gtest/gtest.h>
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