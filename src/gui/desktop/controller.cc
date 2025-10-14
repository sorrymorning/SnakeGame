#include "controller.h"

UserAction_t Controls::convertKeyToAction(int ch) {
  UserAction_t action = {-1};

  switch (ch) {
    case KEY_R:
      action = Start;
      break;
    case KEY_P:
      action = Pause;
      break;
    case KEY_Q:
      action = Terminate;
      break;
    case KEY_LEFT:
      action = Left;
      break;
    case KEY_RIGHT:
      action = Right;
      break;
    case KEY_UP:
      action = Up;
      break;
    case KEY_DOWN:
      action = Down;
      break;
    case KEY_Z:
      action = Action;
      break;
  }

  return action;
}


void Controls::processUserInput(int key,bool hold){
    UserAction_t action = convertKeyToAction(key);
    userInput(action,hold);
    if(action == UserAction_t::Terminate){
        // Выход должен быть)
    }
}


void Controls::updateGame(){
    GameInfo_t game_info_ = updateCurrentState();

    // передать информацию в модель))
}
