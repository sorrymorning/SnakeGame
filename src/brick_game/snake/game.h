#pragma once
#include <vector>
#include "snake.h"  // Предполагается, что у вас есть класс Snake

class GameField {
public:
    // Конструктор (ширина, высота)
    GameField(int width, int height);
    ~GameField();

    // Обновление состояния игры
    void update();

    // Обработка ввода (можно делегировать Controller)
    void setDirection(Direction dir);

    // Получение данных для отрисовки
    GameInfo_t getGameInfo() const;

    // Управление игрой
    void startGame();
    void pauseGame();
    void resetGame();

private:
    int width_;
    int height_;
    int score_;
    int high_score_;
    int level_;
    int speed_;
    bool is_paused_;
    bool is_game_over_;

    Snake snake_;                // Змейка
    std::pair<int, int> food_;   // Координаты еды {x, y}
    std::vector<std::vector<int>> field_data_;  // 2D-поле (0 - пусто, 1 - змейка, 2 - еда, 3 - стена)

    // Внутренние методы
    void spawnFood();            // Создать еду
    void updateField();          // Обновить поле (змейка, еда, столкновения)
    bool checkCollision() const; // Проверить столкновения
};