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


TEST(SnakeGameGameTest, StartGame){
    Game game;
    SnakeGameTest tester;
    tester.userInput(game,UserAction_t::Start,false);
    GameInfo_t info = tester.getGameInfo(game);

    EXPECT_EQ(info.pause,Pause_Actions_t::ACTION_NO_PAUSE);
    EXPECT_EQ(tester.getGameStatus(game),Status::Moving);
}

TEST(SnakeGameGameTest, StartJustFinishGame){
    Game game;
    SnakeGameTest tester;
    tester.userInput(game,UserAction_t::Terminate,false);
    GameInfo_t info = tester.getGameInfo(game);

    EXPECT_EQ(info.pause,Pause_Actions_t::ACTION_EXIT);
    EXPECT_EQ(tester.getGameStatus(game),Status::Ending);
}

TEST(SnakeGameGameTest, PauseGame){
    Game game;
    SnakeGameTest tester;
    tester.userInput(game,UserAction_t::Start,false);
    tester.userInput(game,UserAction_t::Pause,false);
    GameInfo_t info = tester.getGameInfo(game);

    EXPECT_EQ(info.pause,Pause_Actions_t::ACTION_PAUSE);
}

TEST(SnakeGameGameTest, FinishStartGame){
    Game game;
    SnakeGameTest tester;
    tester.setStatus(game,Status::Ending);
    tester.userInput(game,UserAction_t::Start,false);
    GameInfo_t info = tester.getGameInfo(game);

    EXPECT_EQ(info.pause,Pause_Actions_t::ACTION_NO_PAUSE);
    EXPECT_EQ(tester.getGameStatus(game),Status::Moving);
}

TEST(SnakeGameGameTest, FinistJustFinishGame){
    Game game;
    SnakeGameTest tester;
    tester.setStatus(game,Status::Ending);
    tester.userInput(game,UserAction_t::Terminate,false);
    GameInfo_t info = tester.getGameInfo(game);

    EXPECT_EQ(info.pause,Pause_Actions_t::ACTION_EXIT);
    EXPECT_EQ(tester.getGameStatus(game),Status::Ending);
}

TEST(SnakeGameGameTest, IncreaseScore){
    Game game;
    SnakeGameTest tester;
    std::pair<int, int> posBef = tester.getApplePosition(game);
    tester.increaseScore(game);
    std::pair<int, int> posAft = tester.getApplePosition(game);
    EXPECT_NE(posBef,posAft);
}

