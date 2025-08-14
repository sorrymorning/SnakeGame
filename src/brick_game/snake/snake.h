#ifndef SNAKE_H
#define SNAKE_H


#include <vector>
#include <utility>



#define FIELD_H 20
#define FIELD_W 10


enum Direction { UP, DOWN, LEFT, RIGHT };


class Snake {
public:
    Snake(int startX, int startY, int initialLength = 4);
    
    void move();
    void grow();
    bool checkCollision() const;
    void changeDirection(Direction newDir);
    
    const std::vector<std::pair<int, int>>& getBody() const;
    Direction getDirection() const;
    bool isAlive() const;

private:
    std::vector<std::pair<int, int>> body;
    Direction currentDir;
    bool alive;
};









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


typedef struct {
  int **field;     
  int **next;     
  int score;       
  int high_score;  
  int level;       
  int speed;      
  int pause;      
} GameInfo_t;


enum class Status {
    Initial,
    Appearance,
    Moving,
    Eating,
    Pause,
    GameOver,
    Exit
};












#endif