#include "game_test.h"


void SnakeGameTest::setGameScore(Game &game, int score) {
  game.game_info_t_.score = score;
}

int SnakeGameTest::getGameScore(Game &game){
    return game.game_info_t_.score;
}

void SnakeGameTest::eatGame(Game &game) { game.increaseScore(true); }