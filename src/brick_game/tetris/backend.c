#include "inc/backend.h"

State_t *getCurrentState() {
  static State_t state;
  static int initialized = 0;

  if (!initialized) {
    initialized = 1;
    initializeState(&state);
  }

  return &state;
}

int createMatrix(int ***destination, int height, int width) {
  int status = 0;
  size_t ptrs_size = height * sizeof(int *);
  size_t data_size = height * width * sizeof(int);
  int **matrix = calloc(1, ptrs_size + data_size);
  if (matrix != NULL) {
    int *data = (int *)((char *)matrix + ptrs_size);
    for (int i = 0; i < height; i++) {
      matrix[i] = data + i * width;
    }
    *destination = matrix;
  } else {
    status = 1;
  }
  return status;
}

void freeMatrix(int **matrix) {
  if (matrix != NULL) {
    free(matrix);
  }
}

void copyMatrix(int **src, int **dst, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      dst[i][j] = src[i][j];
    }
  }
}

void rotateBlock(int **toMatrix, int **fromMatrix) {
  for (int i = 0; i < SIZE_BLOCK; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      toMatrix[i][j] = fromMatrix[SIZE_BLOCK - j - 1][i];
    }
  }
}

void fillBlock(int **block, int blockType) {
  switch (blockType) {
    case I:
      block[1][0] = 1;
      block[1][1] = 1;
      block[1][2] = 1;
      block[1][3] = 1;
      break;
    case O:
      block[1][1] = 1;
      block[1][2] = 1;
      block[2][1] = 1;
      block[2][2] = 1;
      break;
    case T:
      block[1][1] = 1;
      block[2][0] = 1;
      block[2][1] = 1;
      block[2][2] = 1;
      break;
    case L:
      block[1][2] = 1;
      block[2][0] = 1;
      block[2][1] = 1;
      block[2][2] = 1;
      break;
    case J:
      block[1][0] = 1;
      block[2][0] = 1;
      block[2][1] = 1;
      block[2][2] = 1;
      break;
    case S:
      block[1][1] = 1;
      block[1][2] = 1;
      block[2][0] = 1;
      block[2][1] = 1;
      break;
    case Z:
      block[1][0] = 1;
      block[1][1] = 1;
      block[2][1] = 1;
      block[2][2] = 1;
      break;
  }
}

int **generateBlock() {
  int blockType = rand() % 7;
  int **block = NULL;
  int **temp = NULL;

  createMatrix(&block, SIZE_BLOCK, SIZE_BLOCK);
  createMatrix(&temp, SIZE_BLOCK, SIZE_BLOCK);
  fillBlock(block, blockType);
  int numberRotations = rand() % 4;
  for (int i = 0; i < numberRotations; i++) {
    rotateBlock(temp, block);
    copyMatrix(temp, block, SIZE_BLOCK, SIZE_BLOCK);
  }
  freeMatrix(temp);
  return block;
}

void initializeState(State_t *state_t) {
  state_t->status = Initial;
  int **field;
  int status = createMatrix(&field, FIELD_HEIGHT, FIELD_WIDTH);

  if (status == 0) {
    state_t->field = field;
    state_t->score = 0;
    state_t->level = 1;
    state_t->speed = SPEED;
    state_t->time = get_time();
    state_t->pause = 0;
    state_t->coordX = -3;
    state_t->coordY = 3;
    state_t->is_win = 0;
    state_t->nextBlock = generateBlock();
    state_t->block = generateBlock();
  }

  srand(get_time());
}

void startGame() {
  State_t *state = getCurrentState();
  state->status = Appearance;
}

int blockIsAttached() {
  State_t *state = getCurrentState();
  int attached = 0;
  for (int i = 0; i < SIZE_BLOCK; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      int newX = state->coordX + i + 1;
      int newY = state->coordY + j;

      if (state->block[i][j] == 1) {
        if (newX >= FIELD_HEIGHT) {
          attached = 1;
        } else if ((newX >= 0) && (state->field[newX][newY] == 1)) {
          attached = 1;
        }
      }
    }
  }
  return attached;
}

void moveBlockLeft() {
  State_t *state = getCurrentState();
  int canMoveLeft = 1;

  for (int i = 0; i < SIZE_BLOCK && canMoveLeft; i++) {
    for (int j = 0; j < SIZE_BLOCK && canMoveLeft; j++) {
      int newX = state->coordX + i;
      int newY = state->coordY + j - 1;

      if ((state->block[i][j] == 1) && (newY < 0)) {
        canMoveLeft = 0;
      } else if ((newY >= 0) && (newX < FIELD_HEIGHT) && (newX >= 0) &&
                 (state->block[i][j] == 1)) {
        if ((state->block[i][j] + state->field[newX][newY]) == 2) {
          canMoveLeft = 0;
        }
      }
    }
  }

  if (canMoveLeft == 1) {
    (state->coordY)--;

    int attached = blockIsAttached();
    if (attached == 0) {
      state->status = Moving;
    } else {
      state->status = Attachment;
    }
  }
}

void moveBlockRight() {
  State_t *state = getCurrentState();
  int canMoveLeft = 1;

  for (int i = 0; i < SIZE_BLOCK && canMoveLeft; i++) {
    for (int j = 0; j < SIZE_BLOCK && canMoveLeft; j++) {
      int newX = state->coordX + i;
      int newY = state->coordY + j + 1;

      if ((state->block[i][j] == 1) && (newY >= FIELD_WIDTH)) {
        canMoveLeft = 0;
      } else if ((newY <= FIELD_WIDTH) && (newX < FIELD_HEIGHT) &&
                 (newX >= 0) && (state->block[i][j] == 1)) {
        if ((state->block[i][j] + state->field[newX][newY]) == 2) {
          canMoveLeft = 0;
        }
      }
    }
  }

  if (canMoveLeft == 1) {
    (state->coordY)++;
    int attached = blockIsAttached();
    if (attached == 0) {
      state->status = Moving;
    } else {
      state->status = Attachment;
    }
  }
}

int canRotateBlock(int **newBlock) {
  int canRotate = 1;
  State_t *state = getCurrentState();

  for (int i = 0; i < SIZE_BLOCK && canRotate; i++) {
    for (int j = 0; j < SIZE_BLOCK && canRotate; j++) {
      int newX = state->coordX + i;
      int newY = state->coordY + j;

      if (newBlock[i][j]) {
        if (newX < 0 || newX >= FIELD_HEIGHT || newY < 0 ||
            newY >= FIELD_WIDTH) {
          canRotate = 0;
        } else if (state->field[newX][newY] == 1) {
          canRotate = 0;
        }
      }
    }
  }

  return canRotate;
}

void rotateBlocks() {
  State_t *state = getCurrentState();

  int **newBlock = NULL;
  createMatrix(&newBlock, SIZE_BLOCK, SIZE_BLOCK);
  rotateBlock(newBlock, state->block);

  if (canRotateBlock(newBlock) == 1) {
    freeMatrix(state->block);
    state->block = newBlock;
  } else {
    freeMatrix(newBlock);
  }

  int attached = blockIsAttached();
  if (attached == 0) {
    state->status = Moving;
  } else {
    state->status = Attachment;
  }
}

void spawnNewBlock() {
  State_t *state = getCurrentState();
  if (state->block) freeMatrix(state->block);
  state->block = state->nextBlock;

  state->coordX = -3;
  state->coordY = 3;

  state->nextBlock = generateBlock();

  state->status = Moving;
  state->time = get_time();
}

void moveDown() {
  State_t *state = getCurrentState();
  int attached = blockIsAttached();
  if (!attached) {
    (state->coordX)++;
    state->status = Moving;
  } else {
    state->status = Attachment;
  }
}

void moveFigure(UserAction_t action, bool hold) {
  State_t *state = getCurrentState();
  if (action == Left && !state->pause && !state->is_win)
    moveBlockLeft();
  else if (action == Right && !state->pause && !state->is_win)
    moveBlockRight();
  else if (action == Down && !state->pause && !hold && !state->is_win)
    moveDown();
  else if ((action == Action || action == Up) && !state->pause &&
           !state->is_win)
    rotateBlocks();
  else if (action == Pause)
    state->pause = !state->pause;
  else if (action == Terminate) {
    state->status = Ending;
  }
  if (timer(state, state->speed) && !state->pause && !state->is_win) {
    state->status = Shifting;
  }
}

void updateLevel() {
  State_t *state = getCurrentState();

  if (state->score >= NEW_LEVEL_THRESHOLD) {
    state->level = state->score / NEW_LEVEL_THRESHOLD + 1;
    state->speed = DELAY_MS * pow(0.8, state->level);
  }

  if (state->level > MAX_LEVEL) {
    state->is_win = 1;
    state->status = Ending;
  }
}

int getMaxScore() {
  FILE *file;
  int highScore = 0;
  
  file = fopen("score.txt", "r");
  if (file != NULL) {
    int result = fscanf(file, "%d", &highScore);
    if (result != 1) {
      highScore = 0;  // Сброс если прочитано не 1 значение
    }
    fclose(file);
  }
  return highScore;
}

void saveMaxScore() {
  State_t *state = getCurrentState();
  FILE *file;
  int highScore = getMaxScore();
  if (state->score > highScore) {
    file = fopen("score.txt", "w");
    fprintf(file, "%d", state->score);
    fclose(file);
  }
}

void consumeRows() {
  State_t *state = getCurrentState();
  int consRows = 0;

  for (int i = FIELD_HEIGHT - 1; i >= 0; i--) {
    int countPix = 0;
    for (int j = 0; j < FIELD_WIDTH; j++) {
      countPix += state->field[i][j];
    }

    if (countPix == FIELD_WIDTH) {
      for (int z = i; z > 0; z--) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
          state->field[z][j] = state->field[z - 1][j];
        }
      }
      i++;
      consRows++;
    }
  }

  if (consRows == 1) {
    state->score += 100;
  } else if (consRows == 2) {
    state->score += 300;
  } else if (consRows == 3) {
    state->score += 700;
  } else if (consRows == 4) {
    state->score += 1500;
  }

  saveMaxScore();
  updateLevel();
}

void attachBlock() {
  State_t *state = getCurrentState();

  int gameOver = 0;

  for (int i = 0; i < SIZE_BLOCK; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      int newX = state->coordX + i;
      int newY = state->coordY + j;

      if (newX >= 0 && newX < FIELD_HEIGHT && newY >= 0 && newY < FIELD_WIDTH &&
          state->block[i][j]) {
        state->field[newX][newY] = 1;
      } else if ((newX < 0 || newY < 0) && state->block[i][j]) {
        gameOver = 1;
      }
    }
  }

  if (gameOver) {
    state->status = Ending;
  } else {
    consumeRows();
    state->status = (state->status != Ending) ? Appearance : Ending;
  }
}

void finishGame() {
  State_t *state = getCurrentState();

  freeMatrix(state->block);
  freeMatrix(state->nextBlock);
  freeMatrix(state->field);
}



long long get_time() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (long long)t.tv_sec * 1000 + t.tv_usec / 1000;
}

bool timer(State_t *gs, int delay) {
  bool result = false;
  long long time = get_time();

  if (time - gs->time >= delay) {
    gs->time = time;
    result = true;
  }

  return result;
}

void userInput(UserAction_t action, bool hold) {
  State_t *state = getCurrentState();

  if (state->status == Initial) {
    if (action == Terminate) {
      finishGame();
      state->status = Ending;
    } else if (action == Start) {
      startGame();
    }

  } else if (state->status == Appearance) {
    spawnNewBlock();
  } else if (state->status == Moving) {
    moveFigure(action, hold);
  } else if (state->status == Shifting) {
    moveDown();
  } else if (state->status == Attachment) {
    attachBlock();
  } else if (state->status == Ending) {
    finishGame();
  }
}

int set_pause_state(State_t *state_t){
  int state = ACTION_NO_PAUSE;

  if(state_t->status == Initial){
    state = ACTION_INITIAL;
  }else if(state_t->status == Ending){
    state = ACTION_END;
  }else if(state_t->pause == 1){
    state = ACTION_PAUSE;
  }
  else if(state_t->is_win == 1){
    state = ACTION_WIN;
  }
  return state;
}


GameInfo_t updateCurrentState() {
  State_t *state = getCurrentState();
  GameInfo_t tetris = {0};
  int **displayField = NULL;
  createMatrix(&displayField, FIELD_HEIGHT, FIELD_WIDTH);
  for (int i = 0; i < FIELD_HEIGHT; i++) {
    for (int j = 0; j < FIELD_WIDTH; j++) {
      displayField[i][j] = state->field[i][j];
    }
  }
  for (int i = 0; i < SIZE_BLOCK; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      if (state->block[i][j]) {
        int x = state->coordX + i;
        int y = state->coordY + j;
        if (x >= 0 && x < FIELD_HEIGHT && y >= 0 && y < FIELD_WIDTH) {
          displayField[x][y] = 2;
        }
      }
    }
  }

  tetris.field = displayField;
  tetris.next = state->nextBlock;
  tetris.score = state->score;
  tetris.high_score = getMaxScore();
  tetris.level = state->level;
  tetris.speed = 1000;
  tetris.pause = set_pause_state(state);

  return tetris;

}