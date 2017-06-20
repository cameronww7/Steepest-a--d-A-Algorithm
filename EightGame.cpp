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


#include "EightGame.h"

//===EightGame====================================
// Initialize both array with null so it will
// not have any overflow
//==========================================
EightGame::EightGame() {
	//initial current board
	for (int index = 0; index < BOARD_SIZE; index++) {
		mGameBoard[index] = '\0';
	}
	//initial win state
	for (int index = 0; index < BOARD_SIZE; index++) {
		mWinBoard[index] = '\0';
	}
}


//==================GetBoard========================
// Returns the Game board.
//-------------------------------------------------
// In    :  Nothing
// Return: 	The Game Board
//==================================================
char * EightGame::GetBoard(){
	return mGameBoard;
}

//==================GetWinBoard=====================
// Returns a winning board
//-------------------------------------------------
// In    :  Nothing
// Return: 	The Win Board
//==================================================
char * EightGame::GetWinBoard(){
	return mWinBoard;
}

//=================SetBoard==========================
// Set the initial board
//---------------------------------------------------
// In	 :	Nothing
// Return:  Nothing
//===================================================
bool EightGame::SetBoard (char xArr[]) {
	for (int index = 0; index < BOARD_SIZE; index++) {
		mGameBoard[index] = xArr[index];
	}
	mGameBoard[BOARD_SIZE - 1] = '\0';
	return true;
}

//===================SetWinBoard=====================
// Set the winning board
//---------------------------------------------------
// In	 :	Array to be set as a winning board
// Return:  True if it was called
//===================================================
bool EightGame::SetWinBoard (char xArr[]) {
	for (int index = 0; index < BOARD_SIZE; index++) {
		mWinBoard[index] = xArr[index];
	}
	mWinBoard[BOARD_SIZE - 1] = '\0';
	return true;
}

//================DisplayBoard=======================
// Display the current game board in 3 X 3 format
//---------------------------------------------------
// In	 :	Nothing
// Return:  Nothing
//==================================================
void EightGame::DisplayBoard() {
	for (int currentPosition = 0; currentPosition < BOARD_SIZE; currentPosition++) {
		if ((currentPosition % BOARD_ROW_SIZE) == 0  && currentPosition != 0) {
			cout << std::endl;
		}
		cout << mGameBoard[currentPosition] << " ";
	}
	cout << std::endl;
}

//==============DisplayBoardAtLine====================
// Display the current game board in in specific line
//---------------------------------------------------
// In	 :	Board Level
// Return:  Nothing
//==================================================
void EightGame::DisplayBoardAtLine(int xLevel) {
	for (int currentPosition = (xLevel * BOARD_ROW_SIZE); currentPosition < ((xLevel * BOARD_ROW_SIZE) + BOARD_ROW_SIZE); currentPosition++) {
		cout << mGameBoard[currentPosition] << " ";
	}
}

//=================FindEmptySlot=====================
// Search mGameBoard for the empty slot
//---------------------------------------------------
// In	 :	Nothing
// Return:  If an empty slot was found.
//===================================================
int EightGame::FindEmptySlot () {
	for (int index = 0; index < BOARD_SIZE; index++) {
		if (mGameBoard[index] == 'x') {
			return index;
		}
	}
	return -1;
}

//==============FindCharInBoard=====================
// Search Value from Board
//---------------------------------------------------
// In	 :	Nothing
// Return:  Nothing
//==================================================
int EightGame::FindCharInBoard (char xInput) {
	int foundChar = -1;
	for (int index = 0; index < BOARD_SIZE; index++) {
		if (mGameBoard[index] == xInput) {
			foundChar = index;
		}
	}
	return foundChar;
}

//=====================SwapSpace=====================
// Move the empty slot to the new slot vase on the
// direction input.
//---------------------------------------------------
// In	 :	Desired direction of move
// Return:  Nothing
//===================================================
void EightGame::SwapSpace (int xDirection) {
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

//=================MoveDirection=====================
// Receive direction and make a game move
//---------------------------------------------------
// In	 :	The direction to move
// Return:  If it can move
//===================================================
bool EightGame::MoveDirection (int xDirection) {
	bool ableMove = false;
	if (IsMovable(xDirection)) {
		SwapSpace(xDirection);
		ableMove =  true;
	}
	return ableMove;
}

//=====================IsMovable=====================
// Check if the move is valid
//---------------------------------------------------
// In	 :	Desired Direction to move
// Return:  If it can move
//===================================================
bool EightGame::IsMovable (int xDirection) {
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
		else if (empty > 5 && xDirection == DOWN) {
			ableMove = false;
		}
		//cannot move left
		else if (empty % 3 == 0 && xDirection == LEFT) {
			ableMove = false;
		}
		//cannot move right
		else if (empty % 3 == 2 && xDirection == RIGHT) {
			ableMove = false;
		} else {
			ableMove = true;
		}
	}
	return ableMove;
}

//===================CheckForWin=====================
// Check if the current board is at a win state
//---------------------------------------------------
// In	 :	Nothing
// Return:  Bool if a win had happen
//===================================================
bool EightGame::CheckForWin () {
	bool checkForWin = false;
	if (mGameBoard[0] == mWinBoard[0] &&
	    mGameBoard[1] == mWinBoard[1] &&
	    mGameBoard[2] == mWinBoard[2] &&
	    mGameBoard[3] == mWinBoard[3] &&
	    mGameBoard[4] == mWinBoard[4] &&
	    mGameBoard[5] == mWinBoard[5] &&
	    mGameBoard[6] == mWinBoard[6] &&
	    mGameBoard[7] == mWinBoard[7] &&
	    mGameBoard[8] == mWinBoard[8]) {
		checkForWin = true;
	} else {
		checkForWin = false;
	}
	return checkForWin;
}

//=====================EightGame=====================
// Deep copy Constructor
//---------------------------------------------------
// In	 :	EightGame Obj
// Return:  Nothing
//===================================================
/*
EightGame::EightGame(EightGame &obj){


	for (int index = 0; index < BOARD_SIZE; index++) {
		mGameBoard[index] = obj.GetBoard()[index];
	}
	mGameBoard[BOARD_SIZE - 1] = '\0';

	for (int index = 0; index < BOARD_SIZE; index++) {
		mWinBoard[index] = obj.GetWinBoard()[index];
	}
	mWinBoard[BOARD_SIZE - 1] = '\0';
}
*/

//==================="EightGame="====================
// Deep copy overloader
//---------------------------------------------------
// In	 :	EightGame Obj
// Return:  EightGame Copy
//===================================================
/*
EightGame& EightGame::operator=(const EightGame& rhs){
	//EightGame* Item = new EightGame;

	//Item->SetBoard(rhs.GetBoard());
	//Item->SetWinBoard(rhs.GetWinBoard());

	return rhs;
}*/
