#include "frontend.h"

void print_start_menu() {
  WINDOW *start_menu_window =
      newwin(START_MENU_H, START_MENU_W, (GAME_FIELD_H - START_MENU_H) / 2,
             GAME_FIELD_W - (GAME_FIELD_W - START_MENU_W) / 2 + 1);
  box(start_menu_window, 0, 0);

  mvwhline(start_menu_window, 1, 2, ACS_HLINE, START_MENU_W - 4);
  mvwhline(start_menu_window, START_MENU_H - 2, 2, ACS_HLINE, START_MENU_W - 4);
  mvwvline(start_menu_window, 2, 1, ACS_VLINE, START_MENU_H - 4);
  mvwvline(start_menu_window, 2, START_MENU_W - 2, ACS_VLINE, START_MENU_H - 4);

  int text_width = 20;
  int text_height = 3;

  mvwprintw(start_menu_window, (START_MENU_H - text_height) / 2,
            (START_MENU_W - text_width) / 2 + 1, "Tetris Game");
  mvwprintw(start_menu_window, (START_MENU_H - text_height) / 2 + 1,
            (START_MENU_W - text_width) / 2 + 1, "Made by Austinma");

  mvwprintw(start_menu_window, (START_MENU_H - text_height) / 2 + 3,
            (START_MENU_W - text_width) / 2 + 1, "Press 'r' to start");

  wrefresh(start_menu_window);
  delwin(start_menu_window);
}

void print_pause_menu() {
  WINDOW *pause_menu_window =
      newwin(PAUSE_MENU_H, PAUSE_MENU_W, (GAME_FIELD_H - PAUSE_MENU_H) / 2,
             CONTROLS_W + (GAME_FIELD_W - PAUSE_MENU_W) / 2 + 1);
  box(pause_menu_window, 0, 0);

  mvwhline(pause_menu_window, 1, 2, ACS_HLINE, PAUSE_MENU_W - 4);
  mvwhline(pause_menu_window, PAUSE_MENU_H - 2, 2, ACS_HLINE, PAUSE_MENU_W - 4);
  mvwvline(pause_menu_window, 2, 2, ACS_VLINE, PAUSE_MENU_H - 4);
  mvwvline(pause_menu_window, 2, PAUSE_MENU_W - 3, ACS_VLINE, PAUSE_MENU_H - 4);

  int text_width = 6;
  int text_height = 1;

  mvwprintw(pause_menu_window, (PAUSE_MENU_H - text_height) / 2,
            (PAUSE_MENU_W - text_width) / 2, "Paused");

  wrefresh(pause_menu_window);
  delwin(pause_menu_window);
}

void print_win() {
  WINDOW *win_window =
      newwin(FINISH_GAME_H, FINISH_GAME_W, (GAME_FIELD_H - FINISH_GAME_H) / 2,
             CONTROLS_W + (GAME_FIELD_W - FINISH_GAME_W) / 2 + 1);
  box(win_window, 0, 0);

  mvwhline(win_window, 1, 1, ACS_HLINE, FINISH_GAME_W - 2);
  mvwhline(win_window, FINISH_GAME_H - 2, 1, ACS_HLINE, FINISH_GAME_W - 2);
  mvwvline(win_window, 1, 1, ACS_VLINE, FINISH_GAME_H - 2);
  mvwvline(win_window, 1, FINISH_GAME_W - 2, ACS_VLINE, FINISH_GAME_H - 2);

  int text_width = 11;
  int text_height = 2;

  mvwprintw(win_window, (FINISH_GAME_H - text_height) / 2,
            (FINISH_GAME_W - text_width) / 2, "You win! :)");

  wrefresh(win_window);
  delwin(win_window);
}

void print_game_over(GameInfo_t gi) {
  WINDOW *game_over_window =
      newwin(FINISH_GAME_H, FINISH_GAME_W, (GAME_FIELD_H - FINISH_GAME_H) / 2,
             CONTROLS_W + (GAME_FIELD_W - FINISH_GAME_W) / 2 + 1);
  box(game_over_window, 0, 0);

  mvwhline(game_over_window, 1, 1, ACS_HLINE, FINISH_GAME_W - 2);
  mvwhline(game_over_window, FINISH_GAME_H - 2, 1, ACS_HLINE,
           FINISH_GAME_W - 2);
  mvwvline(game_over_window, 1, 1, ACS_VLINE, FINISH_GAME_H - 2);
  mvwvline(game_over_window, 1, FINISH_GAME_W - 2, ACS_VLINE,
           FINISH_GAME_H - 2);

  int text_width = 12;
  int text_height = 4;

  mvwprintw(game_over_window, (FINISH_GAME_H - text_height) / 2,
            (FINISH_GAME_W - text_width) / 2, "Game over :(");
  mvwprintw(game_over_window, (FINISH_GAME_H - text_height) / 2 + 2,
            (FINISH_GAME_W - text_width) / 2, "Score  %d", gi.score);
  mvwprintw(game_over_window, (FINISH_GAME_H - text_height) / 2 + 3,
            (FINISH_GAME_W - text_width) / 2, "Level  %d", gi.level);

  wrefresh(game_over_window);
  delwin(game_over_window);
}

WINDOW *print_controls() {
  WINDOW *controls_window =
      newwin(GAME_FIELD_H, CONTROLS_W, TOP_MARGIN, LEFT_MARGIN);
  box(controls_window, 0, 0);

  mvwprintw(controls_window, 0, (CONTROLS_W - 8) / 2, "Controls");

  mvwprintw(controls_window, 2, 2, "Start    r");
  mvwprintw(controls_window, 4, 2, "Pause    p");
  mvwprintw(controls_window, 6, 2, "Rotate   z, up arrow");
  mvwprintw(controls_window, 8, 2, "Left     left arrow");
  mvwprintw(controls_window, 10, 2, "Right    right arrow");
  mvwprintw(controls_window, 12, 2, "Down     down arrow");
  mvwprintw(controls_window, 14, 2, "Quit     q");

  return controls_window;
}

WINDOW *print_game_field(GameInfo_t gi) {
  WINDOW *game_window =
      newwin(GAME_FIELD_H, GAME_FIELD_W, TOP_MARGIN, CONTROLS_W + 1);

  box(game_window, 0, 0);
  keypad(game_window, 1);
  nodelay(game_window, 1);

  mvwprintw(game_window, 0, (GAME_FIELD_W - 6) / 2, "Tetris");

  for (int i = 0; i < FIELD_HEIGHT; i++) {
    for (int j = 0; j < FIELD_WIDTH; j++) {
      if (gi.field[i][j] == 1) {
        mvwprintw(game_window, i + 1, 3 * j + 1, "  #");
      } else if (gi.field[i][j] == 2) {
        mvwprintw(game_window, i + 1, 3 * j + 1, "  @");
      } else {
        mvwprintw(game_window, i + 1, 3 * j + 1, "  .");
      }
    }
  }

  return game_window;
}

void print_next_figure(WINDOW *info_window, GameInfo_t gi) {
  mvwprintw(info_window, 2, 2, "Next");

  for (int i = 0; i < SIZE_BLOCK && gi.next; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      if (gi.next[i][j] == 1) {
        mvwprintw(info_window, i + 4, j * 3 + 4, "  #");
      }
    }
  }
}

WINDOW *print_game_info(GameInfo_t gi) {
  WINDOW *info_window = newwin(GAME_FIELD_H, GAME_INFO_W, TOP_MARGIN,
                               CONTROLS_W + GAME_FIELD_W + 1);
  box(info_window, 0, 0);

  mvwprintw(info_window, 0, (GAME_INFO_W - 9) / 2, "Game_Info");

  print_next_figure(info_window, gi);

  mvwprintw(info_window, 8, 2, "High score  %d", gi.high_score);
  mvwprintw(info_window, 11, 2, "Score       %d", gi.score);
  mvwprintw(info_window, 14, 2, "Level       %d", gi.level);
  mvwprintw(info_window, 17, 2, "Speed       %d", gi.speed);

  return info_window;
}

void render(GameInfo_t gi) {
  refresh();

  WINDOW *controls_window = print_controls();
  wrefresh(controls_window);

  WINDOW *game_window = NULL;
  if (gi.pause != ACTION_PAUSE) {
    game_window = print_game_field(gi);
    wrefresh(game_window);
  }

  if (gi.pause == ACTION_INITIAL)
    print_start_menu();
  else if (gi.pause == ACTION_PAUSE)
    print_pause_menu();
  else if (gi.pause == ACTION_WIN)
    print_win();
  else if (gi.pause == ACTION_END)
    print_game_over(gi);
  
  WINDOW *info_window = print_game_info(gi);
  wrefresh(info_window);

  if (game_window != NULL) delwin(game_window);

  delwin(info_window);
  delwin(controls_window);
}