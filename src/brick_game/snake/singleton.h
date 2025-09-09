#ifndef SINGLETON_H
#define SINGLETON_H

#include "game.h"

class Singleton {
private:
    Singleton() {}
    ~Singleton() {}
    
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Game& getSnakeGame();
};




#endif