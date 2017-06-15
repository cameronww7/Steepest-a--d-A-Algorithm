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
#include <fstream>
#include <string>
#include "./EightGame.h"

using namespace std;

// int BOARDSIZE = 9;

void DisplayBoard(char* currentBoard, int size);
void TEST(EightGame* Curr, int size);

//Heuristic function: Counting tiles out of place
int CountingTilesOutOfPlace(char board[]);

//Read from file
void readFromFile(string fileName);

int main() {
	readFromFile("input.txt");

	EightGame Item;
	char test[] = {'1','2','3','6','x','4','8','7', '5', '\0'};

	Item.SetBoard(test, BOARDSIZE);

	cout << "Board: " << Item.GetBoard() << "End"<< endl; 
	// there are overflow in the returning array

	char* tt = Item.GetBoard();
	DisplayBoard(tt, BOARDSIZE);
	//cout << "Is win:: " << Item.CheckForWin() << endl;
	//cout << "Where is _:: " << Item.FindEmptySlot() << endl;

	cout << "------------------" << endl;
	TEST(&Item,BOARDSIZE);

	cout << endl;
	system("PAUSE");
	return 0;
}


//====TEST====================================
//This is use to test/play the game 
void TEST(EightGame* Curr, int size){

	int command;
	char* tt = Curr->GetBoard();

	while(1){
		DisplayBoard(tt, BOARDSIZE);

		cout << "Counting tiles out of place: " 
			<< CountingTilesOutOfPlace(Curr->GetBoard()) << endl << endl;

		cout << "Enter Direction: ";
		cin >> command; 

		if (command != 8
			&& command != 4
			&& command != 6
			&& command != 2)
		{
			cout << "Invalid Move" << endl << endl;
		}
		else
		{
			if(Curr->MoveDirection(command))
			{
				cout << "good Move" << endl;
			}
			else
			{
				cout << "Invalid Move" << endl;
			}

			if(Curr->CheckForWin())
			{
				cout << "!!--WINNER--!!" << endl;
				DisplayBoard(tt, BOARDSIZE);
				break;
			}
		}
	}

	cout << "Exit Game" << endl;
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
		cout << currentBoard[i] << " ";

	}
	cout << endl;
}

int CountingTilesOutOfPlace(char board[]) {
	int count = 0;
	if (board[0] != '1') count++;
	if (board[1] != '2') count++;
	if (board[2] != '3') count++;
	if (board[3] != '8') count++;
	if (board[4] != 'x') count++;
	if (board[5] != '4') count++;
	if (board[6] != '7') count++;
	if (board[7] != '6') count++;
	if (board[8] != '5') count++;
	return count;
}

void readFromFile(string fileName) {
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			cout << line << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}


