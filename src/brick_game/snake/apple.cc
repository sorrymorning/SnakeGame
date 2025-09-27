#include "apple.h"

#include <cstdlib> // для rand()
#include <ctime>   // для time()

Apple::Apple(const std::vector<std::pair<int, int>>& snake_body) {
    std::srand(std::time(0)); // инициализация генератора случайных чисел
    generateNewPosition(snake_body);
}

bool Apple::isPositionValid(const std::vector<std::pair<int, int>>& snake_body, 
                        const std::pair<int, int>& pos) const {
        // Проверяем, не находится ли позиция в теле змейки
        for (const auto& segment : snake_body) {
            if (segment == pos) {
                return false;
            }
        }
        
        // Проверяем, что позиция в пределах поля
        if (pos.first < 0 || pos.first >= FIELD_H || 
            pos.second < 0 || pos.second >= FIELD_W) {
            return false;
        }
                
        return true;
    }
    
void Apple::generateNewPosition(const std::vector<std::pair<int, int>>& snake_body) {
    int max_attempts = 1000; // Защита от бесконечного цикла
    int attempts = 0;
    
    do {
        int x = std::rand() % FIELD_H;
        int y = std::rand() % FIELD_W;
        position_ = std::make_pair(x, y);
        attempts++;
        
    } while (!isPositionValid(snake_body, position_) && attempts < max_attempts);
    
    if (attempts >= max_attempts) {
        // Аварийная позиция (если не нашли свободную)
        position_ = findEmergencyPosition(snake_body);
    }
}

std::pair<int, int> Apple::findEmergencyPosition(const std::vector<std::pair<int, int>>& snake_body) {
    // Ищем первую свободную клетку
    for (int x = 0; x < FIELD_H; ++x) {
        for (int y = 0; y < FIELD_W; ++y) {
            auto pos = std::make_pair(x, y);
            if (isPositionValid(snake_body, pos)) {
                return pos;
            }
        }
    }
    return std::make_pair(0, 0); // Последний резерв
}


bool Apple::isAtPosition(const std::pair<int, int>& pos) const {
    return position_ == pos;
}

std::pair<int, int> Apple::getPosition() const {
    return position_;
}