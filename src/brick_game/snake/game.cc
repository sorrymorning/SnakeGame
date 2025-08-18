#include "game.h"


Game::Game() : status_(Status::Initial){
    game_info_t_.field = new int*[FIELD_H];

    for(int i = 0;i<FIELD_H;++i){
        game_info_t_.field[i] = new int[FIELD_W];
    }
    for (int i = 0; i < FIELD_H; ++i) {
        for (int j = 0; j < FIELD_W; ++j) {
            game_info_t_.field[i][j] = 0;
        }
    }



}