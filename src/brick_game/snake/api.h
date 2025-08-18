#ifndef API_H
#define API_H

#define FIELD_H 20
#define FIELD_W 10




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

#endif