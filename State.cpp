//
// Created by justin on 6/17/17.
//

#include "State.h"

State::State() {
    mHeuristicValue = 0;
}


void State::SetBoard(char * xBoard) {
    mBoardState.SetBoard(xBoard);

}

void State::SetHeuristicValue(int xHValue) {
    mHeuristicValue = xHValue;
}