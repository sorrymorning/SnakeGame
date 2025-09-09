#include "singleton.h"



Game& Singleton::getSnakeGame() {
    static Game snake_game;
    return snake_game;
}



