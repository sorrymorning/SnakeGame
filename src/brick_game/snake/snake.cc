#include "snake.h"

Snake::Snake(int startX, int startY, int initialLength) {
    currentDir = RIGHT; // Начальное направление
    alive = true;
    
    // Создаём змейку горизонтально: [(5,5), (5,6), (5,7),(5,8)]
    for (int i = 0; i < initialLength; ++i) {
        body.push_back({startX, startY + i});
    }
}



void Snake::move() {
    if (!alive) return;
    
    auto head = body.front();
    switch (currentDir) {
        case UP:    head.second -= 1; break;
        case DOWN:  head.second += 1; break;
        case LEFT:  head.first -= 1;  break;
        case RIGHT: head.first += 1;  break;
    }
    body.insert(body.begin(), head);
    body.pop_back();
}


void Snake::grow() {
    body.push_back(body.back());
}


bool Snake::checkCollision() const {
    auto head = body.front();
    
    if (head.first < 0 || head.first >= FIELD_W || 
        head.second < 0 || head.second >= FIELD_H) {
        return true;
    }
    
    for (size_t i = 1; i < body.size(); ++i) {
        if (head == body[i]) return true;
    }
    
    return false;
}


void Snake::changeDirection(Direction newDir) {
    if ((currentDir == LEFT && newDir != RIGHT) ||
        (currentDir == RIGHT && newDir != LEFT) ||
        (currentDir == UP && newDir != DOWN) ||
        (currentDir == DOWN && newDir != UP)) {
        currentDir = newDir;
    }
}

const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

Direction Snake::getDirection() const {
    return currentDir;
}

bool Snake::isAlive() const {
    return alive;
}