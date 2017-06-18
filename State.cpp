/******************************************************************
 * Name	1		:	Cameron Walters
 * Name 2		:	Payaam Emami
 * Name 3		:	Itsarapong Sawangsri
 * Name 4		:	Justin Aebiskiver
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
    mBoardState = xEGBoard;
}


void State::SetBoard(EightGame xEGBoard) {
    mBoardState = xEGBoard;

}

void State::SetHeuristicValue(int xHValue) {
    mHeuristicValue = xHValue;
}


//===CalulateHeuristicOne==========================
// Calulate Heruistic value base on the tile out of
//	position in the board
//	Compare current to the winning state
// Return: 	Heruistic Value:
//	** this does not store the cal value
//==================================================
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



//===CalulateHeuristicTwo==========================
// Calulate Heruistic value base on how far the tile
//	Is from the correct position
// Return: 	Heruistic Value:
//	** this does not store the cal value
//==================================================
int State::CalulateHeuristicTwo(){
	int count = 0;

	int BoardMain;
	int WinMain;

	int DivBoard;
	int ModBoard;

	int DivWin;
	int ModWin;

	for(int index = 0; index < 9; index++)
	{
		// Using int division to calculate vertical different
		// Using int mod to calcuate horizontal different
		// vertical + horizontal = number of move 
		WinMain = index;
		BoardMain = mBoardState.FindCharInBoard(mBoardState.GetWinBoard()[index]);

		DivBoard = BoardMain / 3;
		ModBoard = BoardMain % 3;

		DivWin = WinMain / 3;
		ModWin = WinMain % 3;

		count = count + (abs(DivBoard-DivWin) + abs(ModBoard-ModWin));
	}
	return count;
}

