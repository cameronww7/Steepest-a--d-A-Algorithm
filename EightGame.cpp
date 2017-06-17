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


#include "EightGame.h"

//===FindCharInBoard=====================
//Search Value from Board
// input [IN] - char to find in the board
//	return
//		index where the char is
//======================================
int EightGame::FindCharInBoard (char xInput)
{
	int foundChar = -1;
	for (int index = 0; index < BOARD_SIZE; index++) {
		if (mGameBoard[index] == xInput) {
			foundChar = index;
		}
	} 
	return foundChar;
}

//===SetBoard=====================
//Copy the direction into the private available
// xArr [IN]		- array of board face value
// return
//		true if successfully copy
//====================================== 
bool EightGame::SetBoard (char xArr[])
{
	for (int index = 0; index < BOARD_SIZE; index++) {
		mGameBoard[index] = xArr[index];
	}
	return true;
}

//===CheckForWin=====================
//Check if the current board is at a win state
// return
//		return true if the board is in win state
//====================================== 
bool EightGame::CheckForWin ()
{
	bool checkForWin = false;
	if (mGameBoard[0] == '1' &&
	    mGameBoard[1] == '2' &&
	    mGameBoard[2] == '3' &&
	    mGameBoard[3] == '8' &&
	    mGameBoard[4] == 'x' &&
	    mGameBoard[5] == '4' &&
	    mGameBoard[6] == '7' &&
	    mGameBoard[7] == '6' &&
	    mGameBoard[8] == '5') {
		checkForWin = true;
	} else {
		checkForWin = false;
	}
	return checkForWin;
}


//===FindEmptySlot=====================
//Search m_GameBoard for the empty slot
//	return
//		return an index where empty slot reside
//====================================== 
int EightGame::FindEmptySlot ()
{
	for (int index = 0; index < BOARD_SIZE; index++) {
		if (mGameBoard[index] == 'x') {
			return index;
		}
	}
	return -1;
}


//===SwapSpace=====================
//Move the empty slot to the new slot 
//	vase on the direction input
// direction	[IN] 	- direction to move
//	return
//		None
//====================================== 
void EightGame::SwapSpace (int xDirection)
{
	int empty = FindEmptySlot();
	int newPosition;

	switch (xDirection) {
		case LEFT:  newPosition = empty - 1;
			break;
		case RIGHT: newPosition = empty + 1;
			break;
		case UP:    newPosition = empty - 3;
			break;
		case DOWN:  newPosition = empty + 3;
			break;
		default:
			return;
	}

	char temp = mGameBoard[newPosition];
	mGameBoard[newPosition] = mGameBoard[empty];
	mGameBoard[empty] = temp;

}

//===MoveDirection=====================
//Receive direction and make a game move
// direction	[IN] 	- direction to move
//	return
//		True if successfully make a move
//====================================== 
bool EightGame::MoveDirection (int xDirection)
{
	bool ableMove = false;
	if (IsMovable(xDirection)) {
		SwapSpace(xDirection);
		ableMove =  true;
	}
	return ableMove;
}

//===IsMovable=====================
//check if the move is valid
// direction	[IN] 	- direction to move
//	return
//		return an index where empty slot reside
//====================================== 
bool EightGame::IsMovable (int xDirection)
{
	bool ableMove = false;
	int  empty    = FindEmptySlot();
	
	//Check for invalid input
	if (xDirection != UP   &&
		xDirection != DOWN &&
		xDirection != LEFT &&
		xDirection != RIGHT) {
		ableMove = false;
	} else {
		//cannot move up
		if (empty < 3 && xDirection == UP) {
			ableMove = false;
		}
		//cannot move down
		if (empty > 5 && xDirection == DOWN) {
			ableMove = false;
		}
		//cannot move left
		if (empty % 3 == 0 && xDirection == LEFT) {
			ableMove = false;
		}
		//cannot move right
		if (empty % 3 == 2 && xDirection == RIGHT) {
			ableMove = false;
		}
		ableMove = true;
	}
	return ableMove;
}

//Needs input from text file
char** createBoard(int rows, int columns, char data[])
{
	char** board = new char*[rows];
	int dataIt = 0;

	for (int i = 0; i < rows; i++)
	{
		board[i] = new char[columns];
		for (int j = 0; j < columns; j++)
		{
			board[i][j] = data[dataIt];
			dataIt++;
		}
	}
	return board;
}

void EightGame::displayBoard() {
	for (int currentPosition = 0; currentPosition < 9; currentPosition++) {
		if ((currentPosition % 3) == 0  && currentPosition != 0) {
			cout << std::endl;
		}
		cout << mGameBoard[currentPosition] << " ";
	}
	cout << std::endl;
}