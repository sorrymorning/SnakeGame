#ifndef FRONTEND_H
#define FRONTEND_H

#include <stdbool.h>
#include <string.h>
#include <ncurses.h>
#include "../../brick_game/snake/api.h"
// #include "../../brick_game/snake/game.h"

#define WIN_INIT()         \
  {                        \
    initscr();             \
    noecho();              \
    curs_set(0);           \
    keypad(stdscr, TRUE);  \
    nodelay(stdscr, TRUE); \
    cbreak();              \
  }

#define SPEED 1000
#define NEW_LEVEL_THRESHOLD 600
#define SPEED_STEP 100
#define MAX_LEVEL 10
#define DELAY_MS 1100

#define FIELD_HEIGHT 20
#define FIELD_WIDTH 10
#define SIZE_BLOCK 4

#define KEY_R 114
#define KEY_P 112
#define KEY_Q 113
#define KEY_Z 122

#define GAME_FIELD_H (FIELD_HEIGHT + 2)
#define GAME_FIELD_W (FIELD_WIDTH * 3 + 2)
#define START_MENU_H 8
#define START_MENU_W 24
#define PAUSE_MENU_H 5
#define PAUSE_MENU_W 24
#define FINISH_GAME_H 10
#define FINISH_GAME_W 24
#define GAME_INFO_W 25
#define CONTROLS_W 24

#define TOP_MARGIN 0
#define LEFT_MARGIN 0

#include "ncurses.h"

void render(GameInfo_t gi);

#endif