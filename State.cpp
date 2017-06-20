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
}

State::State(EightGame xEGBoard) {
    mHeuristicValue = 0;
    mCurrentBoard = xEGBoard;
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
	for(int index = 0; index < 9; index++)
	{
		if(this->GetBoardState().GetBoard()[index] 
			!= xRHS.GetBoardState().GetBoard()[index])
		{
			return false;
		}
	}
	


	//if (this->GetHeuristicValue() == xRHS.GetHeuristicValue()) {
	//	return true;
	//}
	return true;
}

bool State::operator>(State & xRHS) {
	if (this->GetHeuristicValue() > xRHS.GetHeuristicValue()) {
		return true;
	}
	return false;
}