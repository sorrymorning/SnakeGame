#include "game.h"


Game::Game() : status_(Status::Initial),action_(UserAction_t::Start),snake_(5,5),timer_(){
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


// void Game::actionSnake(UserAction_t action, bool hold){
    

//     if(timer_.isExpired()){
//         moveSnake(action,hold);
//         timer_.reset();
//     }else if(!pause){
//         if (action >= UserAction_t::Left && action <= UserAction_t::Down){
//             snake_.changeDirection(action);
//         }else if(action == UserAction_t::Pause){
//             pause = !pause;
//         }
//         // тут можно добавить ускорение наверное
//     }

//     if(action == UserAction_t::Terminate){
//         // функция по завершении игры :)
//     }

    

// }

void Game::actionSnake(UserAction_t action, bool hold) {
    // 1. Обработка системных команд (всегда)
    handleSystemActions(action);
    
    // 2. Если пауза - только системные команды
    if (!pause){
        handleGameActions(action, hold);

    }
    
}

void Game::handleSystemActions(UserAction_t action) {
    switch (action) {
        case UserAction_t::Terminate:
            // завершение игры
            break;
        case UserAction_t::Pause:
            pause = !pause;
            if (pause) timer_.pause();
            else timer_.resume();
            break;
        default:
            break;
    }
}

void Game::handleGameActions(UserAction_t action, bool hold) {
    // Движение по таймеру
    if (timer_.isExpired()) {
        moveSnake(action, hold);
        timer_.reset();
    }
    
    // Изменение направления (немедленно)
    if (isDirectionAction(action)) {
        snake_.changeDirection(action);
    }
    
    // // Дополнительные действия
    // if (action == UserAction_t::SpeedUp && !hold) {
    //     increaseSpeed();
    // }
}

bool Game::isDirectionAction(UserAction_t action) const {
    return action >= UserAction_t::Left && action <= UserAction_t::Down;
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