#include "game.h"
#include <cstdlib>  // Для rand()
#include <ctime>    // Для time()


GameField::GameField(int width, int height) 
    : width_(width), height_(height), score_(0), high_score_(0), level_(1), speed_(200), is_paused_(false), is_game_over_(false) {
    
    // Инициализация поля
    field_data_.resize(height_, std::vector<int>(width_, 0));

    // Начальное положение змейки (центр)
    snake_ = Snake(width_ / 2, height_ / 2);

}


void userInput(UserAction_t action, bool hold){

}