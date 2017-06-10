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

#include <iostream>
#include <cstring>
#include <stdio.h>
#include "./eightGame.h"

using namespace std;

// int BOARDSIZE = 9;

void DisplayBoard(char* currentBoard, int size);

int main() {
	EightGame Item;
	char test[9] = {'1','2','3','5','6','7','4','0', '8'};

	Item.SetBoard(test, BOARDSIZE);

	cout << "Board: " << Item.GetBoard() << "End"<< endl; 
	// there are overflow in the returning array

	char* tt = Item.GetBoard();
	DisplayBoard(tt, BOARDSIZE);

	return 0;
}


//==DisplayBoard=====================================
//Display the current game board in 3 X 3 format
// currentBoard [IN]  - array contain board face value
// size [IN]		  - size of the array
//==================================================
void DisplayBoard(char* currentBoard, int size){
	for(int i = 0; i < size; i++)
	{
		if((i % 3) == 0  && i != 0)
		{
			cout << endl;
		}

		if(currentBoard[i] != '0')
		{
			cout << currentBoard[i] << " ";
		}
		else
		{
			cout << "_" << " ";
		}	
	}
	cout << endl;
}
