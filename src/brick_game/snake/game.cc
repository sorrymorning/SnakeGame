#include "game.h"
#include <map>

Game::Game() : status_(Status::Initial),action_(UserAction_t::Start),snake_(5,5),timer_(),apple_(snake_.getBody()){
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
    game_info_t_.high_score = readIntFromFile();
    game_info_t_.pause = Pause_Actions_t::ACTION_INITIAL;
    game_info_t_.speed = 0;
    game_info_t_.score = 0;

    
}   


void Game::userInput(UserAction_t action, bool hold){
    if (status_ == Status::Initial){
        if(action==UserAction_t::Start)startGame();
        else if (action==UserAction_t::Terminate) finishGame();
    }else if (status_ == Status::Moving){
        actionSnake(action,hold);
    }else if (status_ == Status::Ending){
        if(action==UserAction_t::Start)startGame();
        else if (action==UserAction_t::Terminate) finishGame();
    }
}

void Game::increaseScore(bool eat){
    if(eat){
        apple_.generateNewPosition(snake_.getBody());
        game_info_t_.score++;
        if(game_info_t_.score%5==0 && game_info_t_.level <= 10){
            game_info_t_.level++;
            increaseSpeed();
        }
        if(game_info_t_.score == 200){
            status_=Status::Ending;
            game_info_t_.pause = ACTION_WIN;
        }
    }
}


void Game::startGame(){
    if(status_== Status::Initial){
        snake_ = Snake();
        
        status_ = Status::Moving;
        game_info_t_.pause = Pause_Actions_t::ACTION_NO_PAUSE;
    } else if(status_== Status::Ending){
        if(game_info_t_.score > game_info_t_.high_score){
             game_info_t_.high_score = game_info_t_.score;
            writeIntToFile(game_info_t_.score);
        }
        game_info_t_.score = 0;
        game_info_t_.level = 1;
        timer_.reset();
        snake_ = Snake();
        
        status_ = Status::Moving;
        game_info_t_.pause = Pause_Actions_t::ACTION_NO_PAUSE;
    }
    
}

void Game::finishGame(){
    
    if(game_info_t_.score > game_info_t_.high_score){
        writeIntToFile(game_info_t_.score);
    }
    status_ = Status::Ending;
    game_info_t_.pause = ACTION_EXIT;
}

void Game::writeIntToFile(int value) {
    std::ofstream out("score.txt", std::ios::trunc); // откроет файл или создаст новый
    if (!out) {
        return;
    }
    out << value;
}

int Game::readIntFromFile() {
    std::ifstream in("score.txt");
    if (!in) {
        return 0;
    }
    int value = 0;
    in >> value;
    return value;
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

void Game::increaseSpeed() {
    std::map<int, int> level_speeds = {
        {1, 1000}, {2, 925}, {3, 850}, {4, 775}, {5, 700},
        {6, 625}, {7, 550}, {8, 475}, {9, 400}, {10, 325}
    };
    
    if (level_speeds.find(game_info_t_.level) != level_speeds.end()) {
        // Set the base interval for the current level
        timer_.setBaseInterval(level_speeds[game_info_t_.level]);
        game_info_t_.speed = 1000 - level_speeds[game_info_t_.level];
    }
}

void Game::speedUp() {
    timer_.toggleSpeedUp();
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
    
    // Дополнительные действия
    if (action == UserAction_t::Action && !hold) {
        speedUp();
    }
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
        
        snake_.move(willEatApple);
        increaseScore(willEatApple);
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


