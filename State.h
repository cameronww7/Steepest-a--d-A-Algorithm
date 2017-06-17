//
// Created by justin on 6/17/17.
//

#ifndef STATE_H
#define STATE_H

#include "EightGame.h"

/*
 * Represents state of a board at a given time, along with their heuristic value,
 * with the idea that they be used for the queues when implementing the search algorithms.
 */
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
