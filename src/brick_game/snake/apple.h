#ifndef APPLE_H_
#define APPLE_H_


#include <utility>
#include "api.h"

class Apple {
public:
    Apple();
    
    void generateNewPosition();
    bool isAtPosition(const std::pair<int, int>& position) const;
    std::pair<int, int> getPosition() const;

private:
    std::pair<int, int> position_;
};

// Добавить все для яблока там генерацию и тд
#endif