#ifndef SNAKE_H
#define SNAKE_H


#include <vector>
#include <utility>
#include "api.h"


#define FIELD_H 20
#define FIELD_W 10


enum Direction { UP,  LEFT, DOWN, RIGHT };


class Snake {
public:
    Snake(int startX = 5, int startY = 5, int initialLength = 4);
    
    void move();
    void grow();
    bool checkCollision(const std::pair<int, int>& position) const;
    void changeDirection(UserAction_t action);
    std::pair<int, int> getNextHeadPosition() const;
    const std::vector<std::pair<int, int>>& getBody() const;
    Direction getDirection() const;
    bool isAlive() const;
    Direction actionToDirection(UserAction_t action);

private:
    std::vector<std::pair<int, int>> body;
    Direction currentDir;
    bool alive;
};

#endif