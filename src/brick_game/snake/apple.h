#ifndef APPLE_H_
#define APPLE_H_


#include "api.h"
#include <utility>
#include <vector>
class Apple {
public:
    Apple(const std::vector<std::pair<int, int>>& snake_body);
    bool isPositionValid(const std::vector<std::pair<int, int>>& snake_body, 
                        const std::pair<int, int>& pos) const;
    void generateNewPosition(const std::vector<std::pair<int, int>>& snake_body);
    bool isAtPosition(const std::pair<int, int>& position) const;
    std::pair<int, int> getPosition() const;
    std::pair<int, int> findEmergencyPosition(const std::vector<std::pair<int, int>>& snake_body);
private:
    std::pair<int, int> position_;
};

// Добавить все для яблока там генерацию и тд
#endif