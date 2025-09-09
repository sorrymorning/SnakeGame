#ifndef BAKCEND_H_
#define BAKCEND_H_

#include "singleton.h"
#include "api.h"

extern "C" void userInput(UserAction_t action, bool hold);
extern "C" GameInfo_t updateCurrentState();

#endif


