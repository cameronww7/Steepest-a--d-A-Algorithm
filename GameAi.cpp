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


#include "GameAi.h"

GameAi::GameAi() {}

//=======NEED TO BE CHANGE==================
bool GameAi::SetGameBoard(EightGame  xSetItem)
{
	mCurrentBoard = xSetItem;
	return true;
}



//==CountingTilesOutOfPlace=====================================
// Count tile out of place
// return - number of tile out of place
//==================================================
int GameAi::CountingTilesOutOfPlace() 
{
	int count = 0;
	if (0 != mCurrentBoard.FindCharInBoard('1')) count++;
	if (1 != mCurrentBoard.FindCharInBoard('2')) count++;
	if (2 != mCurrentBoard.FindCharInBoard('3')) count++;
	if (3 != mCurrentBoard.FindCharInBoard('8')) count++;
	if (4 != mCurrentBoard.FindCharInBoard('x')) count++;
	if (5 != mCurrentBoard.FindCharInBoard('4')) count++;
	if (6 != mCurrentBoard.FindCharInBoard('7')) count++;
	if (7 != mCurrentBoard.FindCharInBoard('6')) count++;
	if (8 != mCurrentBoard.FindCharInBoard('5')) count++;
	return count;
}


//===CalulateHeuristicOne==========================
// Calculate Heuristic value base on the tile out of
//	position in the board
//	Compare current to the winning state
// Return: 	Heuristic Value:
//	** this does not store the calculate value
//==================================================
int GameAi::CalulateHeuristicOne() {
	int count = 0;

	if (mCurrentBoard.GetBoard()[0] != mCurrentBoard.GetWinBoard()[0]) count++;
	if (mCurrentBoard.GetBoard()[1] != mCurrentBoard.GetWinBoard()[1]) count++;
	if (mCurrentBoard.GetBoard()[2] != mCurrentBoard.GetWinBoard()[2]) count++;
	if (mCurrentBoard.GetBoard()[3] != mCurrentBoard.GetWinBoard()[3]) count++;
	if (mCurrentBoard.GetBoard()[4] != mCurrentBoard.GetWinBoard()[4]) count++;
	if (mCurrentBoard.GetBoard()[5] != mCurrentBoard.GetWinBoard()[5]) count++;
	if (mCurrentBoard.GetBoard()[6] != mCurrentBoard.GetWinBoard()[6]) count++;
	if (mCurrentBoard.GetBoard()[7] != mCurrentBoard.GetWinBoard()[7]) count++;
	if (mCurrentBoard.GetBoard()[8] != mCurrentBoard.GetWinBoard()[8]) count++;
	return count;
}


//===CalulateHeuristicTwo==========================
// Calculate Heuristic value base on how far the tile
//	Is from the correct position
// Return: 	Heuristic Value:
//	** this does not store the calculations value
//==================================================
int GameAi::CalulateHeuristicTwo() {
	int count = 0;

	int boardMain;

	int divBoard;
	int modBoard;

	int divWin;
	int modWin;

	for (int index = 0; index < 9; index++) {
		boardMain = mCurrentBoard.FindCharInBoard(mCurrentBoard.GetWinBoard()[index]);

		divBoard = boardMain / 3;
		modBoard = boardMain % 3;

		divWin = index / 3;
		modWin = index % 3;

		count = count + (abs(divBoard-divWin) + abs(modBoard-modWin));
	}
	return count;
}
