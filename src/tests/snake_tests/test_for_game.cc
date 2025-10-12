#include "game_test.h"

TEST(SnakeGameGameTest, Initialization){
    Game game;
    SnakeGameTest tester;
    GameInfo_t info = tester.getGameInfo(game);

    for (int i = 0; i < FIELD_H; ++i) {
        for (int j = 0; j < FIELD_W; ++j) {
            EXPECT_EQ(info.field[i][j], 0);
        }
    }   


    EXPECT_NE(info.field,nullptr);
    EXPECT_EQ(info.next,nullptr);
    EXPECT_EQ(info.level,1);
    EXPECT_EQ(info.high_score,0);
    EXPECT_EQ(info.pause,Pause_Actions_t::ACTION_INITIAL);
    EXPECT_EQ(info.speed,0);
    EXPECT_EQ(info.score,0);

}
