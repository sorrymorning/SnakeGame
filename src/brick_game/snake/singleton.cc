#include "sigleton.h"



static SnakeGame& getSnakeGame(){
    static Game snake_game;
    return snake_game;
}


