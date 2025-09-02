#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton {
private:
    Singleton() {}
    ~Singleton() {}
    
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static SnakeGame& getSnakeGame();
};




#endif