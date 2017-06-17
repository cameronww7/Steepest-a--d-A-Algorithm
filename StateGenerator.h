//
// Created by justin on 6/17/17.
//

#ifndef STATE_GENERATOR_H
#define STATE_GENERATOR_H

#include <list>
#include "State.h"

/*
 * This class will be used to create a list of possible moves given the current state of the board
 * Doesn't work correctly currently.
 */
class StateGenerator {
public:
    list <State> GenerateStateList();
    void setCurrentState(EightGame);
    void PrintList(list<State>);
private:
    State mCurrentState;
};


#endif //STATE_GENERATOR_H
