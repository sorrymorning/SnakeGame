#include "game.h"


Game::Game() : status_(Status::Initial),action_(UserAction_t::Start),snake_(){
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

}   


void Game:userInput(UserAction_t action, bool hold){


    if (state == Status::Initial){
        startGame();
    }else if (state == Status::Initial){
        spawnGame();
    }else if (state == Status::Moving){
        //movesnake();
    }else if (state == Status::Eating){
        // eat();
    }else if (state == Status::Pause){
        
    }else if (state == Status::GameOver){

    }else if (state == Status::Exit){

    }
}