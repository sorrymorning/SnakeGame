#include <gtest/gtest.h>
#include "../src/brick_game/snake/game.h"
auto main(int argc, char **argv) -> int {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
