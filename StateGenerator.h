//
// Created by justin on 6/17/17.
//

#ifndef STATE_GENERATOR_H
#define STATE_GENERATOR_H

#include <list>
#include "State.h"

class StateGenerator {
public:
    list <State> GenerateStateList();
    void setCurrentState(EightGame);
    void PrintList(list<State>);
private:
    State mCurrentState;
};


#endif //STATE_GENERATOR_H
