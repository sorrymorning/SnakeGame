#ifndef GAME_TEST_
#define GAME_TEST_

#include <gtest/gtest.h>
#include "../../brick_game/snake/game.h"
#include "../../brick_game/snake/api.h"

class SnakeGameTest{
    public:
        void setGameScore(Game &game, int score);
        int getGameScore(Game &game);
        void eatGame(Game &game);
        void generateApple(Game& game, const std::vector<std::pair<int, int>>& snake_body);
        std::pair<int, int> getApplePosition(Game& game);
        
        void setSnakeDirection(Snake& snake, Direction dir);
        Direction getSnakeDirection(const Snake& snake);

        void moveSnake(Snake& snake, bool willEatApple);
        std::pair<int, int> getSnakeHead(const Snake& snake);
        const std::vector<std::pair<int, int>>& getSnakeBody(const Snake& snake);

        bool checkSnakeCollision(const Snake& snake, const std::pair<int,int>& pos);


        GameInfo_t getGameInfo(const Game& game);

        void userInput(Game& game,UserAction_t action, bool hold);
        Status getGameStatus(const Game& game);
        void setStatus(Game& game, Status state);
        void increaseScore(Game& game);
        void setScore(Game& game,int score);
};

#endif