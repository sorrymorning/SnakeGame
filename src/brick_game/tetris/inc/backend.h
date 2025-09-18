#ifndef S21_TETRIS_BACKEND_H
#define S21_TETRIS_BACKEND_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>

#include "defines.h"
#include "ncurses.h"

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef enum {
  Initial,
  Appearance,
  Moving,
  Shifting,
  Attachment,
  Ending
} Status_t;

typedef struct {
  int status;
  int **field;
  int **block;
  int **nextBlock;
  int coordX;
  int coordY;
  int score;
  int level;
  int pause;
  int speed;
  long long time;
  int is_win;

} State_t;

typedef enum { I, O, T, L, J, S, Z } Block;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

GameInfo_t updateCurrentState();
State_t *getCurrentState();
int createMatrix(int ***destination, int height, int width);
void freeMatrix(int **matrix);
void copyMatrix(int **src, int **dst, int height, int width);
void rotateBlock(int **toMatrix, int **fromMatrix);
void fillBlock(int **block, int blockType);
int **generateBlock();
unsigned long long currentTimeMillis();
unsigned long long processTimer();
void initializeState();
void startGame();
int blockIsAttached();
void moveBlockLeft();
void moveBlockRight();
int canRotateBlock(int **newBlock);
void rotateBlocks();
void spawnNewBlock();
void moveDown();
void updateLevel();
int getMaxScore();
void saveMaxScore();
void consumeRows();
void attachBlock();
void finishGame();
void moveFigure(UserAction_t action, bool hold);
void speedBlock(bool hold);
long long get_time();
bool timer(State_t *gs, int delay);
void userInput(UserAction_t action, bool hold);

#endif