#include "game.h"


Game::Game() : status_(Status::Initial),action_(UserAction_t::Start),snake_(5,5),timer_(),apple_(){
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
    game_info_t_.pause = Pause_Actions_t::ACTION_INITIAL;
    game_info_t_.speed = 100;
    game_info_t_.score = 0;

    
}   


void Game::userInput(UserAction_t action, bool hold){
    if (status_ == Status::Initial){
        if(action==UserAction_t::Start)startGame();
    }else if (status_ == Status::Moving){
        actionSnake(action,hold);
    }else if (status_ == Status::Ending){

    }else if (status_ == Status::Exit){
        
    }
}

void Game::increaseScore(){
    snake_.grow(); // Растем сначала
    apple_.generateNewPosition();
    game_info_t_.score++;
    if(game_info_t_.score%5==0 && game_info_t_.level <= 10){
        game_info_t_.level++;
    }
}


void Game::startGame(){
    snake_ = Snake();
    status_ = Status::Moving;
    game_info_t_.pause = Pause_Actions_t::ACTION_NO_PAUSE;
    
}




void Game::actionSnake(UserAction_t action, bool hold) {
    // 1. Обработка системных команд (всегда)
    handleSystemActions(action);
    
    // 2. Если пауза - только системные команды
    if (game_info_t_.pause == ACTION_NO_PAUSE){
        handleGameActions(action, hold);
    }
    
}

void Game::handleSystemActions(UserAction_t action) {
    switch (action) {
        case UserAction_t::Terminate:
            // завершение игры
            break;
        case UserAction_t::Pause:
            game_info_t_.pause = (game_info_t_.pause==ACTION_NO_PAUSE)? ACTION_PAUSE : ACTION_NO_PAUSE;
            if (game_info_t_.pause==ACTION_PAUSE) timer_.pause();
            else {
                timer_.resume();
            }

            break;
        default:
            break;
    }
}

void Game::handleGameActions(UserAction_t action, bool hold) {
    // Движение по таймеру
    if (timer_.isExpired() && status_!=Status::Initial) {
        moveSnake(action, hold);
        timer_.reset();
        snake_.resetDirectionChanged();
    }
    
    // Изменение направления (немедленно)
    if (isDirectionAction(action) && !snake_.isDirectionChanged()) {
        snake_.changeDirection(action);
        snake_.markDirectionChanged();
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

    
    if(!snake_.checkCollision(nextHead)){
        bool willEatApple = (nextHead == apple_.getPosition());
        
        snake_.move();
        if(willEatApple){
            increaseScore();
        }
    }else{
        game_info_t_.pause = Pause_Actions_t::ACTION_END;
        status_ = Status::Ending;
    }

}

GameInfo_t Game::updateCurrentState(){
    clearStateField();
    const auto& coordApple = apple_.getPosition(); 
    game_info_t_.field[coordApple.first][coordApple.second] = 2;

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


