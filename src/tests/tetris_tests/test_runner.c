#include <check.h>
#include <stdlib.h>

#include "../brickgame/tetris/inc/backend.h"

START_TEST(s21_tetris_1) {
  initializeState();

  State_t *state = getCurrentState();

  ck_assert_int_eq(state->score, 0);
  ck_assert_int_eq(state->level, 1);
  ck_assert_int_eq(state->speed, 1000);
  ck_assert_int_eq(state->pause, 0);
  ck_assert_ptr_ne(state->field, NULL);
  ck_assert_ptr_ne(state->block, NULL);
  ck_assert_ptr_ne(state->nextBlock, NULL);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_2) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  ck_assert_int_eq(state->status, Appearance);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_3) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_4) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(KEY_LEFT), false);
  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_5) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(KEY_RIGHT), false);
  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_6) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  for (int i = 0; i < 6; i++) {
    userInput(updateUserAction(KEY_RIGHT), false);
  }

  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_7) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(KEY_UP), false);
  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_8) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);

  while (state->status != Attachment) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  userInput(updateUserAction(ERR), false);
  ck_assert_int_eq(state->status, Appearance);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_9) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  for (int i = 0; i < 10; i++) {
    userInput(updateUserAction(KEY_RIGHT), false);
  }
  userInput(updateUserAction(KEY_UP), false);
  userInput(updateUserAction(KEY_UP), false);
  userInput(updateUserAction(KEY_UP), false);
  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST
START_TEST(s21_tetris_10) {
  initializeState();
  GameInfo_t tetris = updateCurrentState();
  ck_assert_int_eq(tetris.score, 0);
  ck_assert_int_eq(tetris.level, 1);
  ck_assert_int_eq(tetris.speed, 1000);
  ck_assert_int_eq(tetris.pause, 0);
  ck_assert_ptr_ne(tetris.field, NULL);
  ck_assert_ptr_ne(tetris.next, NULL);
  freeMatrix(tetris.field);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_11) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(KEY_P), false);

  userInput(updateUserAction(KEY_UP), false);
  userInput(updateUserAction(KEY_UP), false);
  userInput(updateUserAction(KEY_UP), false);
  ck_assert_int_eq(state->status, Moving);
  finishGame();
}

START_TEST(s21_tetris_12) {
  initializeState();
  State_t *state = getCurrentState();
  for (int i = 0; i < 10; i++) {
    state->field[19][i] = 1;
  }
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  while (state->status != Attachment) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  ck_assert_int_eq(state->status, Attachment);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(ERR), false);
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += state->field[19][i];
  }
  ck_assert_int_ne(sum, 10);
  finishGame();
}
START_TEST(s21_tetris_13) {
  initializeState();
  State_t *state = getCurrentState();
  for (int j = 18; j < 20; j++) {
    for (int i = 0; i < 10; i++) {
      state->field[j][i] = 1;
    }
  }
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  while (state->status != Attachment) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  ck_assert_int_eq(state->status, Attachment);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(ERR), false);
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += state->field[19][i];
  }
  ck_assert_int_ne(sum, 10);
  finishGame();
}
START_TEST(s21_tetris_14) {
  initializeState();
  State_t *state = getCurrentState();
  for (int j = 17; j < 20; j++) {
    for (int i = 0; i < 10; i++) {
      state->field[j][i] = 1;
    }
  }
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  while (state->status != Attachment) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  ck_assert_int_eq(state->status, Attachment);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(ERR), false);
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += state->field[19][i];
  }
  ck_assert_int_ne(sum, 10);
  finishGame();
}
START_TEST(s21_tetris_15) {
  initializeState();
  State_t *state = getCurrentState();
  for (int j = 16; j < 20; j++) {
    for (int i = 0; i < 10; i++) {
      state->field[j][i] = 1;
    }
  }
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  while (state->status != Attachment) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  ck_assert_int_eq(state->status, Attachment);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(ERR), false);
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += state->field[19][i];
  }
  ck_assert_int_ne(sum, 10);
  finishGame();
}

START_TEST(s21_tetris_16) {
  initializeState();
  State_t *state = getCurrentState();
  for (int i = 0; i < 10; i++) {
    state->field[19][i] = 1;
  }
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  state->level = 12;
  while (state->status != Attachment) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  userInput(updateUserAction(ERR), false);
  ck_assert_int_eq(state->status, Ending);
  ck_assert_int_eq(state->is_win, 1);
  finishGame();
}

START_TEST(s21_tetris_17) {
  initializeState();
  State_t *state = getCurrentState();

  userInput(updateUserAction(KEY_Q), false);
  ck_assert_int_eq(state->status, Ending);
  // finishGame();
}

START_TEST(test_moveBlockLeft_border) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  state->coordY = -1;
  int oldY = state->coordY;
  moveBlockLeft();
  ck_assert_int_le(state->coordY, oldY);
  finishGame();
}
END_TEST

START_TEST(test_moveBlockLeft_ok) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  state->coordY = 5;
  int oldY = state->coordY;
  moveBlockLeft();
  ck_assert_int_le(state->coordY, oldY - 1);
  finishGame();
}
END_TEST

START_TEST(test_moveBlockRight_border) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  state->coordY = FIELD_WIDTH - SIZE_BLOCK;
  int oldY = state->coordY;
  moveBlockRight();
  ck_assert_int_le(state->coordY, oldY + 1);
  finishGame();
}
END_TEST

START_TEST(test_moveBlockRight_ok) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  state->coordY = 3;
  int oldY = state->coordY;
  moveBlockRight();
  ck_assert_int_le(state->coordY, oldY + 1);
  finishGame();
}
END_TEST

START_TEST(test_canRotateBlock_ok) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  state->coordX = 5;
  state->coordY = 5;
  int **rotated;
  createMatrix(&rotated, SIZE_BLOCK, SIZE_BLOCK);
  rotateBlock(rotated, state->block);
  int res = canRotateBlock(rotated);
  ck_assert_int_eq(res, 1);  // можно повернуть
  freeMatrix(rotated);
  finishGame();
}
END_TEST

int sumMatrix(int **mat) {
  int sum = 0;
  for (int i = 0; i < SIZE_BLOCK; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      sum += mat[i][j];
    }
  }
  return sum;
}

START_TEST(test_fill_block) {
  int **matrix;

  for (int i = 0; i < 7; i++) {
    createMatrix(&matrix, SIZE_BLOCK, SIZE_BLOCK);
    fillBlock(matrix, i);
    ck_assert_int_eq(sumMatrix(matrix), 4);
    freeMatrix(matrix);
  }
}
END_TEST

START_TEST(test_ending) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(ERR), false);
  state->status = Ending;
  ck_assert_int_eq(state->status, Ending);
  userInput(updateUserAction(ERR), false);
  ck_assert_int_eq(state->status, Ending);
}
END_TEST

START_TEST(test_shifting) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  userInput(updateUserAction(ERR), false);
  userInput(updateUserAction(ERR), false);
  state->status = Shifting;
  ck_assert_int_eq(state->status, Shifting);
  userInput(updateUserAction(KEY_DOWN), false);
  // ck_assert_int_eq(state->status,Shifting);
}
END_TEST

START_TEST(s21_tetris_18) {
  initializeState();
  State_t *state = getCurrentState();

  for (int i = 0; i < 20; i++) {
    state->field[i][9] = 1;
  }
  userInput(updateUserAction(KEY_R), false);
  for (int i = 0; i < SIZE_BLOCK; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      state->block[i][j] = 0;
    }
  }
  fillBlock(state->block, 1);
  userInput(updateUserAction(ERR), false);

  for (int i = 0; i < 5; i++) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  ck_assert_int_eq(state->status, Moving);
  for (int i = 0; i < 5; i++) {
    userInput(updateUserAction(KEY_RIGHT), false);
  }

  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_19) {
  initializeState();
  State_t *state = getCurrentState();

  for (int i = 0; i < 20; i++) {
    state->field[i][0] = 1;
  }
  userInput(updateUserAction(KEY_R), false);
  for (int i = 0; i < SIZE_BLOCK; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      state->block[i][j] = 0;
    }
  }
  fillBlock(state->block, 1);
  userInput(updateUserAction(ERR), false);

  for (int i = 0; i < 5; i++) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  ck_assert_int_eq(state->status, Moving);
  for (int i = 0; i < 5; i++) {
    userInput(updateUserAction(KEY_LEFT), false);
  }

  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_20) {
  initializeState();
  State_t *state = getCurrentState();
  userInput(updateUserAction(KEY_R), false);
  for (int i = 0; i < SIZE_BLOCK; i++) {
    for (int j = 0; j < SIZE_BLOCK; j++) {
      state->block[i][j] = 0;
    }
  }
  fillBlock(state->block, 1);
  userInput(updateUserAction(ERR), false);

  for (int i = 0; i < 5; i++) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  ck_assert_int_eq(state->status, Moving);
  for (int i = 0; i < 5; i++) {
    userInput(updateUserAction(KEY_Z), false);
  }

  ck_assert_int_eq(state->status, Moving);
  finishGame();
}
END_TEST

START_TEST(s21_tetris_21) {
  initializeState();
  State_t *state = getCurrentState();

  for (int i = 0; i < 10; i++) {
    state->field[0][i] = 1;
  }
  userInput(updateUserAction(KEY_R), false);
  while (state->status != Ending) {
    userInput(updateUserAction(KEY_DOWN), false);
  }
  ck_assert_int_eq(state->status, Ending);

  finishGame();
}
END_TEST

Suite *test_tetris(void) {
  Suite *s = suite_create("Tetris Tests");
  TCase *tc = tcase_create("Tests");
  tcase_add_test(tc, s21_tetris_1);
  tcase_add_test(tc, s21_tetris_2);
  tcase_add_test(tc, s21_tetris_3);
  tcase_add_test(tc, s21_tetris_4);
  tcase_add_test(tc, s21_tetris_5);
  tcase_add_test(tc, s21_tetris_6);
  tcase_add_test(tc, s21_tetris_7);
  tcase_add_test(tc, s21_tetris_8);
  tcase_add_test(tc, s21_tetris_9);
  tcase_add_test(tc, s21_tetris_10);
  tcase_add_test(tc, s21_tetris_11);
  tcase_add_test(tc, s21_tetris_12);
  tcase_add_test(tc, s21_tetris_13);
  tcase_add_test(tc, s21_tetris_14);
  tcase_add_test(tc, s21_tetris_15);
  tcase_add_test(tc, s21_tetris_16);
  tcase_add_test(tc, s21_tetris_17);
  tcase_add_test(tc, s21_tetris_18);
  tcase_add_test(tc, s21_tetris_19);
  tcase_add_test(tc, s21_tetris_20);
  tcase_add_test(tc, s21_tetris_21);

  tcase_add_test(tc, test_moveBlockLeft_border);
  tcase_add_test(tc, test_moveBlockLeft_ok);
  tcase_add_test(tc, test_moveBlockRight_border);
  tcase_add_test(tc, test_moveBlockRight_ok);
  tcase_add_test(tc, test_canRotateBlock_ok);
  tcase_add_test(tc, test_fill_block);
  tcase_add_test(tc, test_ending);
  tcase_add_test(tc, test_shifting);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  int i = 0;
  int fail_count = 0;
  Suite *test_functions[] = {test_tetris(), NULL};
  char *line = "---------------\n";
  while (test_functions[i]) {
    printf("%s", line);
    SRunner *sr = srunner_create(test_functions[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    fail_count += srunner_ntests_failed(sr);
    srunner_free(sr);
    i++;
    printf("%s", line);
  }

  if (fail_count != 0) {
    fail_count = 1;
  }
  return fail_count;
}