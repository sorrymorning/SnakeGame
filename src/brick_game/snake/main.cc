#include "game.h"
#include <iostream>
#include <iomanip>


void printArray(int** mas) {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << std::setw(4) << mas[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    Game game;
    GameInfo_t field = game.updateCurrentState();
    printArray(field.field);
    game.userInput(UserAction_t::Left,false); // здесь старт идет
    game.userInput(UserAction_t::Right,false);
    game.userInput(UserAction_t::Down,false);
    // game.userInput(UserAction_t::Right,false);
    field = game.updateCurrentState();
    std::cout << "---------\n";
    printArray(field.field);
}