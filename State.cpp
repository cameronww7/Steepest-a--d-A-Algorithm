/******************************************************************
 * Name	1		:	Cameron Walters
 * Name 2		:	Payaam Emami
 * Name 3		:	Itsarapong Sawangsri
 * Name 4		:	Justin Shelley
 * Name 5		:	Kenny Nham
 * Project Name	:	Assignment 1
 * Due Date		:	6/20
 * Objectives	: Implementing a steepest-ascent/-descent hill-
 * 				: climbing algorithm and A* algorithm to solve
 * 				: the 8-puzzle problem.
 *****************************************************************/


#include "State.h"

State::State() {
    mHeuristicValue = 0;
    mOldMove 	    = 0;
}

State::State(EightGame xEGBoard) {
    mCurrentBoard 	= xEGBoard;
    mHeuristicValue = 0;
    mOldMove 		= 0;
}

void State::SetBoard(EightGame xEGBoard) {
    mCurrentBoard.SetBoard(xEGBoard.GetBoard());
    mCurrentBoard.SetWinBoard(xEGBoard.GetWinBoard());
}

void State::SetHeuristicValue(int xHValue) {
    mHeuristicValue = xHValue;
}

void State::DisplayState() {
	mCurrentBoard.DisplayBoard();
}

State State::operator=(const State & xRHS) {
	return xRHS;
}

bool State::operator==(State & xRHS) {
	bool returnBool = true;
	for(int index = 0; index < BOARD_SIZE; index++) {
		if(this->GetBoardState().GetBoard()[index] 
			!= xRHS.GetBoardState().GetBoard()[index]) {
			returnBool = false;
		}
	}
	return returnBool;
}

bool State::operator>(State & xRHS) {
	bool returnBool = false;
	if (this->GetHeuristicValue() > xRHS.GetHeuristicValue()) {
		returnBool = true;
	}
	return returnBool;
}
