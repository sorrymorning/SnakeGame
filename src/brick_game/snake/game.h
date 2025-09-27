#ifndef GAME_H
#define GAME_H


#include "api.h"
#include "snake.h"
#include "timer.h"
#include "apple.h"
#include <ncurses.h>


class Game{

    private:
        Status status_;
        GameInfo_t game_info_t_;
        UserAction_t action_;

        Snake snake_;
        Timer timer_;
        Apple apple_;
        void clearStateField();

    public:

        Game();
        void userInput(UserAction_t action, bool hold);
        void actionSnake(UserAction_t action, bool hold);
        void handleSystemActions(UserAction_t action);
        void handleGameActions(UserAction_t action, bool hold);
        bool isDirectionAction(UserAction_t action) const;
        void moveSnake(UserAction_t action,bool hold);
        GameInfo_t updateCurrentState();
        void startGame();
        void increaseScore(bool eat);
        void increaseSpeed();
        void speedUp();

};




#endif