#include "snake.h"

Snake::Snake(int startX, int startY, int initialLength) {
    currentDir = LEFT; // Начальное направление
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
        case UP:    head.first -= 1; break;
        case DOWN:  head.first += 1; break;
        case LEFT:  head.second -= 1;  break;
        case RIGHT: head.second += 1;  break;
    }
    body.insert(body.begin(), head);
    body.pop_back();
}

std::pair<int, int> Snake::getNextHeadPosition() const {
    if (!alive) return body.front();
    
    auto nextHead = body.front();
    switch (currentDir) {
        case UP:    nextHead.first -= 1; break;
        case DOWN:  nextHead.first += 1; break;
        case LEFT:  nextHead.second -= 1;  break;
        case RIGHT: nextHead.second += 1;  break;
    }
    return nextHead;
}

std::pair<int, int> Snake::getHeadPosition() const{
    return body.front();
}

void Snake::grow() {
    body.push_back(body.back());
}


bool Snake::checkCollision(const std::pair<int, int>& position) const {
    const auto& [x, y] = position;
    
    // Проверка границ поля
    if (x < 0 || x >= FIELD_H || y < 0 || y >= FIELD_W) {
        return true;
    }
    
    // Проверка столкновения с телом (исключая хвост, который будет удален)
    for (size_t i = 0; i < body.size() - 1; ++i) {
        if (x == body[i].first && y == body[i].second) {
            return true;
        }
    }
    
    return false;
}


void Snake::changeDirection(UserAction_t action) {
    Direction newDir = actionToDirection(action);
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


Direction Snake::actionToDirection(UserAction_t action){
    Direction dir = UP;
    switch(action){
        case Up:dir = UP;break;
        case Left:dir = LEFT;break;
        case Right:dir = RIGHT;break;
        case Down:dir = DOWN;break;
        default: break;
    }
    return dir;
}


void Snake::resetDirectionChanged() {
    directionChanged_ = false;
}

void Snake::markDirectionChanged() {
    directionChanged_ = true;
}

bool Snake::isDirectionChanged() const {
    return directionChanged_;
}
