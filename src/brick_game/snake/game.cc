#include "Game.hpp"
#include <cstdlib> // для rand()
#include <ctime>   // для time()

Game::Game(int width, int height) 
    : width(width), height(height), snake(width / 2, height / 2), score(0) {
    state = Initial;
    std::srand(std::time(0)); // Инициализация генератора случайных чисел
    spawnFood();
}

void Game::update() {
    if (state != PLAYING) return;
    
    snake.move();

    if (snake.checkCollision(width, height)) {
        state = GAME_OVER;
        return;
    }
    
    auto head = snake.getBody().front();
    if (head == food) {
        snake.grow();
        score += 10;
        spawnFood();
    }
}

void Game::spawnFood() {
    int x, y;
    bool onSnake;
    do {
        onSnake = false;
        x = std::rand() % width;
        y = std::rand() % height;
        
        // Проверка, не появилась ли еда на змейке
        for (const auto& segment : snake.getBody()) {
            if (segment.first == x && segment.second == y) {
                onSnake = true;
                break;
            }
        }
    } while (onSnake);
    
    food = {x, y};
}

void Game::handleInput(char key) {
    switch (key) {
        case 'w': snake.changeDirection(UP); break;
        case 's': snake.changeDirection(DOWN); break;
        case 'a': snake.changeDirection(LEFT); break;
        case 'd': snake.changeDirection(RIGHT); break;
        case 'p': state = (state == PLAYING) ? PAUSED : PLAYING; break;
        case ' ': if (state == MENU || state == GAME_OVER) reset(); break;
    }
}

void Game::reset() {
    snake = Snake(width / 2, height / 2); // Новая змейка по центру
    score = 0;
    spawnFood();
    state = PLAYING;
}

// Геттеры
const Snake& Game::getSnake() const { return snake; }
std::pair<int, int> Game::getFood() const { return food; }
int Game::getScore() const { return score; }
GameState Game::getState() const { return state; }
int Game::getWidth() const { return width; }
int Game::getHeight() const { return height; }