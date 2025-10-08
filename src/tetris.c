

#ifdef TETRIS
#include "brick_game/tetris/inc/backend.h"
#endif
#ifdef SNAKE
#include "brick_game/snake/api.h"
#endif
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
  while (is_playing!=0) {
    GameInfo_t tetris = updateCurrentState();
    int ch = getch();
    render(tetris);
    timeout(10);
    userInput(updateUserAction(ch), false);

    if (tetris.pause == ACTION_EXIT) {
      is_playing = 0;
      
    }
    #ifdef TETRIS
      freeMatrix(tetris.field);
    #endif
  }
}

int main() {
  WIN_INIT();
  game_loop();
  endwin();

  return 0;
}
