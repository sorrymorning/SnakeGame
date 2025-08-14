#ifndef GAME_H
#define GAME_H

#include "Snake.hpp"
#include <utility> // для std::pair

enum GameState { MENU, PLAYING, PAUSED, GAME_OVER };

class Game {
public:
    Game(int width = FIELD_W, int height = FIELD_H); // Размер поля по умолчанию
    
    void update();          
    void spawnFood();       
    void handleInput(char key);
    void reset();           // Сброс игры
    
    // Геттеры для View
    const Snake& getSnake() const;
    GameState getState() const;

private:
    Snake snake;
    std::pair<int, int> food;
    int width, height;
    int score;
    GameState state;
};



#endif