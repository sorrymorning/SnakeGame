#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "api.h"
#include "snake.h"


enum class Status {
    Initial,
    // Appearance,
    Moving,
    Eating,
    Pause,
    GameOver,
    Exit
};

class Game{

    private:
        Status status_;
        GameInfo_t game_info_t_;
        UserAction_t action_;

        Snake snake_;

        int pause;
        void clearStateField();

    public:

        Game();
        void userInput(UserAction_t action, bool hold);
        void actionSnake(UserAction_t action, bool hold);
        void moveSnake(UserAction_t action,bool hold);
        GameInfo_t updateCurrentState();
        void startGame();

};




#endif