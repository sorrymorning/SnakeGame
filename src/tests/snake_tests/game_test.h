#ifndef GAME_TEST_
#define GAME_TEST_

#include "../../brick_game/snake/game.h"
#include "../../brick_game/snake/api.h"

class SnakeGameTest{
    public:
        void setGameScore(Game &game, int score);
        int getGameScore(Game &game);
        void eatGame(Game &game);
};

#endif