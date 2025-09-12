#include "singleton.h"


extern "C" void userInput(UserAction_t action, bool hold){
    // s21::
    Singleton::getSnakeGame().userInput(action,hold);
}


extern "C" GameInfo_t updateCurrentState(){
    return Singleton::getSnakeGame().updateCurrentState();
}

