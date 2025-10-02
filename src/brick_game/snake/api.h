#ifndef API_H
#define API_H

#define FIELD_H 20
#define FIELD_W 10

#include <stdbool.h>

typedef enum{
  ACTION_NO_PAUSE,
  ACTION_PAUSE,
  ACTION_INITIAL,
  ACTION_WIN,
  ACTION_END,
  ACTION_EXIT
} Pause_Actions_t;



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

typedef enum {
    Initial,
    Appearance,
    Moving,
    // Eating
    Pausing,
    Ending
} Status;

#ifdef __cplusplus
extern "C" {
#endif

void userInput(UserAction_t action, bool hold);

GameInfo_t updateCurrentState();

#ifdef __cplusplus
}
#endif
#endif