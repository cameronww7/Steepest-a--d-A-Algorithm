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

//=======NEED TO BE CHANGE==================
bool GameAi::SetGameBoard(EightGame xSetItem)
{
	mCurrentBoard = xSetItem;
	return true;
}

//==CountingTilesOutOfPlace=====================================
//Count tile out of place
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
