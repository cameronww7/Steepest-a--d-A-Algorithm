#include <iostream>
using namespace std;
#include "EightGame.h"

//===FindCharInBoard=====================
//Search Value from Board
// input [IN] - char to find in the board
//	return
//		index where the char is
//======================================
int EightGame::FindCharInBoard(char input)
{
	for(int i = 0; i < BOARDSIZE; i++)
	{
		if(m_GameBoard[i] == input)
		{
			return i;
		}
	}

	return -1;
}

//===SetBoard=====================
//Copy the direction into the private valiable
// arr [IN]		- array of board face value
// size [IN] 	- size of array
// return
//		true if successfully copoy
//====================================== 
bool EightGame::SetBoard(char  arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		m_GameBoard[i] = arr[i];
	}
	return true;
}


//===CheckForWin=====================
//Check if the current board is at a win state
// return
//		return true if the board is in win state
//====================================== 
bool EightGame::CheckForWin()
{
	if(m_GameBoard[0] == '1'
		&& m_GameBoard[1] == '2'
		&& m_GameBoard[2] == '3' 
		&& m_GameBoard[3] == '8' 
		&& m_GameBoard[4] == 'x' 
		&& m_GameBoard[5] == '4' 
		&& m_GameBoard[6] == '7'  
		&& m_GameBoard[7] == '6' 
		&& m_GameBoard[8] == '5' 
	)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//===FindEmptySlot=====================
//Search m_GameBoard for the empty slot
//	return
//		return an index wher empty slot reside
//====================================== 
int EightGame::FindEmptySlot()
{
	for(int i = 0; i < BOARDSIZE; i++)
	{
		if(m_GameBoard[i] == 'x')
		{
			return i;
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
void EightGame::SwapSpace(int direction)
{
	int empty = FindEmptySlot();
	int newPosition;

	switch (direction){
		case LEFT: newPosition = empty - 1;
			break;
		case RIGHT: newPosition = empty + 1;
			break;
		case UP: newPosition = empty - 3;
			break;
		case DOWN: newPosition = empty + 3;
			break;
		default:
			return;
	}

	char temp = m_GameBoard[newPosition];
	m_GameBoard[newPosition] = m_GameBoard[empty];
	m_GameBoard[empty] = temp;

}

//===MoveDirection=====================
//Receive direction and make a game move
// direction	[IN] 	- direction to move
//	return
//		True if successfully make a move
//====================================== 
bool EightGame::MoveDirection(int direction)
{
	if(IsMovable(direction))
	{
		SwapSpace(direction);
		return true;
	}
	return false;
}

//===IsMovable=====================
//check if the move is valid
// direction	[IN] 	- direction to move
//	return
//		return an index wher empty slot reside
//====================================== 
bool EightGame::IsMovable(int direction)
{
	int empty = FindEmptySlot();
	
	if (direction != UP
		&& direction != DOWN
		&& direction != LEFT
		&& direction != RIGHT)
	{
		//invalid input
		return false;
	}

	if(empty < 3 && direction == UP){
		//no up
		return false;
	}
	if(empty > 5  && direction == DOWN){
		// no down
		return false;
	}
	if(empty % 3 == 0   && direction == LEFT){
		// no left
		return false;
	}
	if(empty % 3 == 2 && direction == RIGHT){
		// no right
		return false;
	}
	return true;
}
