#include "brick_game/snake/api.h"

int main() {
  WIN_INIT();
  game_loop();
  endwin();

  return 0;
}

void game_loop() {
  int is_playing = 1;
  initializeState();
  while (is_playing) {
    State_t *state = getCurrentState();
    GameInfo_t tetris = updateCurrentState();
    int ch = getch();
    render(state->status, state->is_win, tetris);
    if (state->status == Ending) {
      while (ch != 'r' && ch != 'q') ch = getch();
      initializeState();
    }

    timeout(10);
    userInput(updateUserAction(ch), false);

    if (state->status == Ending && ch == KEY_Q) {
      is_playing = 0;
    }
    freeMatrix(tetris.field);
  }
}
