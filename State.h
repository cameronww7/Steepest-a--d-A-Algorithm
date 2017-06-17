//
// Created by justin on 6/17/17.
//

#ifndef STATE_H
#define STATE_H

#include "EightGame.h"

class State {
public:
    State();
    State(EightGame);
    void SetBoard             (EightGame);
    EightGame GetBoardState() { return  mBoardState;};
    void SetHeuristicValue    (int);
    int  GetHeuristicValue()  {return  mHeuristicValue;};
private:
    EightGame mBoardState;
    int       mHeuristicValue;
};


#endif
