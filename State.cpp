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

//==================SetBoard========================
// Takes in a passed in board and assigns it to a
// class member variable.
//-------------------------------------------------
// In    : EightGame Board
// Return: 	Nothing
//==================================================
void State::SetBoard(EightGame xEGBoard) {
    mCurrentBoard.SetBoard(xEGBoard.GetBoard());
    mCurrentBoard.SetWinBoard(xEGBoard.GetWinBoard());
}

//==================SetHeuristicValue===============
// Takes in a Heuristic value and then assigns it
// to a member variable.
//-------------------------------------------------
// In    : a Heuristic value
// Return: 	Nothing
//==================================================
void State::SetHeuristicValue(int xHValue) {
    mHeuristicValue = xHValue;
}

//==================DisplayState===================
// Displays the current contents of the member
// variable board.
//-------------------------------------------------
// In    :  Nothing
// Return: 	Nothing
//==================================================
void State::DisplayState() {
	mCurrentBoard.DisplayBoard();
}

//================="operator="======================
// A overload function of the = operator.
//-------------------------------------------------
// In    : EightGame Board
// Return: 	Nothing
//==================================================
State State::operator=(const State & xRHS) {
	return xRHS;
}

//================="operator=="=====================
// A overload function of the == operator.
// Will take in a state to be checked if it is
// the same state as its being compared to.
//-------------------------------------------------
// In    :  State to be compared
// Return: 	If the states are the same or not.
//==================================================
bool State::operator==(State & xRHS) {
	bool returnBool = true;
	for (int index = 0; index < BOARD_SIZE; index++) {
		if (this->GetBoardState().GetBoard()[index] != xRHS.GetBoardState().GetBoard()[index]) {
			returnBool = false;
		}
	}
	return returnBool;
}

//==================operator>=======================
// A overload function of the > operator.
// Will take in a state to be compared if it is
// greater than the state being compared too.
//-------------------------------------------------
// In    :  State to be compared
// Return: 	If the state is greater
//==================================================
bool State::operator>(State & xRHS) {
	bool returnBool = false;
	if (this->GetHeuristicValue() > xRHS.GetHeuristicValue()) {
		returnBool = true;
	}
	return returnBool;
}
