#include "game.h"


Game::Game() : status_(Status::Initial),action_(UserAction_t::Start),snake_(5,5){
    game_info_t_.field = new int*[FIELD_H];

    for(int i = 0;i<FIELD_H;++i){
        game_info_t_.field[i] = new int[FIELD_W];
    }

    for (int i = 0; i < FIELD_H; ++i) {
        for (int j = 0; j < FIELD_W; ++j) {
            game_info_t_.field[i][j] = 0;
        }
    }   

    game_info_t_.next = nullptr;
    game_info_t_.level = 1;
    game_info_t_.high_score = 0;
    game_info_t_.pause = 0;
    game_info_t_.speed = 100;

    pause = 0;
}   


void Game::userInput(UserAction_t action, bool hold){
    if (status_ == Status::Initial){
        startGame();
    }else if (status_ == Status::Moving){
        actionSnake(action,hold);
    }else if (status_ == Status::Eating){
        // eat();
    }else if (status_ == Status::Pause){
        
    }else if (status_ == Status::GameOver){

    }else if (status_ == Status::Exit){

    }
}


void Game::startGame(){
    snake_ = Snake();
    status_ = Status::Moving;
}


void Game::actionSnake(UserAction_t action, bool hold){
    
    if(!pause){
        if (action == UserAction_t::Left || action == UserAction_t::Right){
            snake_.changeDirection(action);
        }else if(action == UserAction_t::Pause){
            pause = !pause;
        }
        // тут можно добавить ускорение наверное
    }
    if(action == UserAction_t::Terminate){
        // функция по завершении игры :)
    }

    // тут if для таймера как в тетрисе
    moveSnake(action,hold);

}



void Game::moveSnake(UserAction_t action,bool hold){
    (void)action;
    (void)hold;


    std::pair<int, int> nextHead = snake_.getNextHeadPosition();
        std::cout << snake_.getDirection();

    if(!snake_.checkCollision(nextHead)){
        snake_.move();
    }

}

GameInfo_t Game::updateCurrentState(){

    clearStateField();
    for (const auto& segment : snake_.getBody()) {
        game_info_t_.field[segment.first][segment.second] = 1;
    }
    return game_info_t_;
}


void Game::clearStateField(){
    for(int i = 0;i<FIELD_H;i++){
        for(int j = 0;j<FIELD_W;j++){
            game_info_t_.field[i][j] = 0;
        }
    }
}