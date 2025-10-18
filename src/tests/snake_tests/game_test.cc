#include "game_test.h"


void SnakeGameTest::setGameScore(Game &game, int score) {
  game.game_info_t_.score = score;
}

int SnakeGameTest::getGameScore(Game &game){
    return game.game_info_t_.score;
}


void SnakeGameTest::eatGame(Game &game) { game.increaseScore(true); }


void SnakeGameTest::generateApple(Game& game, const std::vector<std::pair<int, int>>& snake_body) {
    game.apple_.generateNewPosition(snake_body);
}

std::pair<int, int> SnakeGameTest::getApplePosition(Game& game) {
    return game.apple_.getPosition();
}

void SnakeGameTest::setSnakeDirection(Snake& snake, Direction dir) {
    snake.currentDir = dir;
}

Direction SnakeGameTest::getSnakeDirection(const Snake& snake) {
    return snake.currentDir;
}

void SnakeGameTest::moveSnake(Snake& snake, bool willEatApple) {
    snake.move(willEatApple);
}

std::pair<int, int> SnakeGameTest::getSnakeHead(const Snake& snake) {
    return snake.getHeadPosition();
}

const std::vector<std::pair<int, int>>& SnakeGameTest::getSnakeBody(const Snake& snake) {
    return snake.getBody();
}

bool SnakeGameTest::checkSnakeCollision(const Snake& snake, const std::pair<int,int>& pos) {
    return snake.checkCollision(pos);
}


GameInfo_t SnakeGameTest::getGameInfo(const Game& game){
  return game.game_info_t_;
}

void SnakeGameTest::userInput(Game& game,UserAction_t action, bool hold){
    game.userInput(action,hold);
}

Status SnakeGameTest::getGameStatus(const Game& game){
    return game.getStatus();
}

void SnakeGameTest::setStatus(Game& game, Status state){
    game.status_ = state;
}

void SnakeGameTest::increaseScore(Game& game){
    game.increaseScore(true);
}
