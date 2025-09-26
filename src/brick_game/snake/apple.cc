#include "apple.h"
#include <cstdlib> // для rand()
#include <ctime>   // для time()

Apple::Apple() {
    std::srand(std::time(0)); // инициализация генератора случайных чисел
    generateNewPosition();
}

void Apple::generateNewPosition() {
    // Генерация случайной позиции в пределах сетки
    int x = std::rand() % FIELD_H;
    int y = std::rand() % FIELD_W;
    position_ = std::make_pair(x, y);
}


bool Apple::isAtPosition(const std::pair<int, int>& pos) const {
    return position_ == pos;
}

std::pair<int, int> Apple::getPosition() const {
    return position_;
}