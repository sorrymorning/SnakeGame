#ifndef GAME_H
#define GAME_H


#include "api.h"
#include "snake.h"


enum class Status {
    Initial,
    Appearance,
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
        


    public:

        Game();

};




#endif