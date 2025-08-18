#ifndef SNAKE_H
#define SNAKE_H


#include <vector>
#include <utility>



#define FIELD_H 20
#define FIELD_W 10


enum Direction { UP, DOWN, LEFT, RIGHT };


class Snake {
public:
    Snake(int startX, int startY, int initialLength = 4);
    
    void move();
    void grow();
    bool checkCollision() const;
    void changeDirection(Direction newDir);
    
    const std::vector<std::pair<int, int>>& getBody() const;
    Direction getDirection() const;
    bool isAlive() const;

private:
    std::vector<std::pair<int, int>> body;
    Direction currentDir;
    bool alive;
};

#endif