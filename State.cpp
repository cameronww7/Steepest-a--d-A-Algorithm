//
// Created by justin on 6/17/17.
//

#include "State.h"

State::State() {
    mHeuristicValue = 0;
}

State::State(EightGame xEGBoard) {
    mHeuristicValue = 0;
    mBoardState = xEGBoard;
}


void State::SetBoard(EightGame xEGBoard) {
    mBoardState = xEGBoard;

}

void State::SetHeuristicValue(int xHValue) {
    mHeuristicValue = xHValue;
}