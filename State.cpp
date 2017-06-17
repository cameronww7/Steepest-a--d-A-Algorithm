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

int State::CalulateHeuristicOne(){
	int count = 0;
	if (mBoardState.GetBoard()[0] != mBoardState.GetWinBoard()[0]) count++;
	if (mBoardState.GetBoard()[1] != mBoardState.GetWinBoard()[1]) count++;
	if (mBoardState.GetBoard()[2] != mBoardState.GetWinBoard()[2]) count++;
	if (mBoardState.GetBoard()[3] != mBoardState.GetWinBoard()[3]) count++;
	if (mBoardState.GetBoard()[4] != mBoardState.GetWinBoard()[4]) count++;
	if (mBoardState.GetBoard()[5] != mBoardState.GetWinBoard()[5]) count++;
	if (mBoardState.GetBoard()[6] != mBoardState.GetWinBoard()[6]) count++;
	if (mBoardState.GetBoard()[7] != mBoardState.GetWinBoard()[7]) count++;
	if (mBoardState.GetBoard()[8] != mBoardState.GetWinBoard()[8]) count++;
	return count;
}