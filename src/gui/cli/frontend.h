#ifndef FRONTEND_H
#define FRONTEND_H

#include <stdbool.h>
#include <string.h>

#include "../../brickgame/tetris/inc/backend.h"
#include "ncurses.h"

void render(int status, int win, GameInfo_t gi);

#endif