#include "brick_game/snake/api.h"
#include "gui/cli/frontend.h"

UserAction_t updateUserAction(int ch) {
  UserAction_t action = {-1};

  if (ch == KEY_R) {
    action = Start;
  } else if (ch == KEY_P)
    action = Pause;
  else if (ch == KEY_Q)
    action = Terminate;
  else if (ch == KEY_LEFT)
    action = Left;
  else if (ch == KEY_RIGHT)
    action = Right;
  else if (ch == KEY_UP)
    action = Up;
  else if (ch == KEY_DOWN)
    action = Down;
  else if (ch == KEY_Z)
    action = Action;

  return action;
}

void game_loop() {
  int is_playing = 1;
  // initializeState();
  while (is_playing) {
    // State_t *state = getCurrentState();
    GameInfo_t tetris = updateCurrentState();
    int ch = getch();
    // render(state->status, state->is_win, tetris);
    render(tetris);
    // if (state->status == Ending) {
    //   while (ch != 'r' && ch != 'q') ch = getch();
    //   // initializeState();
    // }

    timeout(10);
    userInput(updateUserAction(ch), false);

    if (tetris.pause == ACTION_EXIT) {
      is_playing = 0;
    }
    // freeMatrix(tetris.field);
  }
}

int main() {
  WIN_INIT();
  game_loop();
  endwin();

  return 0;
}






// Initizialize переписать в части тетриса засунунть его в updateCurrentState
// 
// 
// 
// 
// 
// 
// 
// 
// 
