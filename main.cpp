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
#include <cstdlib>
#include "GameAi.h"
using namespace std;

const int BOARD_SIZE = 9;

void displayBoard (char * xCurrentBoard);

//This is use to test/play the game
void testGameAndPlay (EightGame * xCurr);

//Heuristic function: Counting tiles out of place
int countingTilesOutOfPlace (char xBoard[]);

void readFromFile (string      xFileName,
				   EightGame & xInit);

int main() {
	EightGame init;
	EightGame item;
	State current;
	GameAi generator;
	//GameAi mainAi;


	readFromFile("input.txt", init);

	//Just testing stuff out here
	cout << "Current board state:" << endl;
	current.SetBoard(init);
	generator.setCurrentState(current.GetBoardState());
	cout << "Generating state list: " << endl;
	list<State> stateList = generator.GenerateStateList();
	//generator.PrintList(stateList);
	generator.PrintLocalList();


	cout << "------------------" << std::endl;
	cout << "------------------" << std::endl;

	cout << "initial board from file: " << std::endl;
	displayBoard(init.GetBoard());
	cout << "Goal state from file: " << std::endl;
	displayBoard(init.GetWinBoard());

	//char test[] = {'1','2','3','6','x','4','8','7', '5', '\0'};

	item.SetBoard(init.GetBoard());
	item.SetWinBoard(init.GetWinBoard());

	//mainAi.SetGameBoard(init);

	cout << "Board: " << init.GetBoard() << " End " << std::endl;

	char * board = item.GetBoard();
	displayBoard(board);
	//current.SetBoard(init);
	//Set current


	cout <<"H(n) 1 : "<< current.CalulateHeuristicOne() << std::endl;
	cout <<"H(n) 2 : "<< current.CalulateHeuristicTwo() << std::endl;
	cout <<"H(n) 3 : "<< current.CalulateHeuristicTwo() << std::endl;
//  cout << "Is win:: " << Item.CheckForWin() << endl;
//  cout << "Where is _:: " << Item.FindEmptySlot() << endl;

	cout << "------------------" << std::endl;
	//testGameAndPlay(&item);

	cout << std::endl;
	system("PAUSE");
	return 0;
}


//====TEST====================================
//This is use to test/play the game 
void testGameAndPlay (EightGame * xCurr) {

	int command;
	char * board = xCurr->GetBoard();

	while (1) { // XX Why is this while(1)? while True?
		displayBoard(board);

		cout << "Counting tiles out of place: " 
			<< countingTilesOutOfPlace(xCurr->GetBoard()) << std::endl << std::endl;

		cout << "Enter Direction: ";
		cin >> command; 

		if (command != 8 &&
			command != 4 &&
			command != 6 &&
			command != 2) {
			cout << "Invalid Move" << std::endl << std::endl;
		} else {
			if (xCurr->MoveDirection(command)) {
				cout << "good Move" << std::endl;
			} else {
				cout << "Invalid Move" << std::endl;
			}

			if (xCurr->CheckForWin()) {
				cout << "!!--WINNER--!!" << std::endl;
				displayBoard(board);
				break;
			}
		}
	}
	cout << "Exit Game" << std::endl;
}

//==DisplayBoard=====================================
//Display the current game board in 3 X 3 format
// currentBoard [IN]  - array contain board face value
// size [IN]		  - size of the array
//==================================================
void displayBoard(char * xCurrentBoard) {
	for (int currentPosition = 0; currentPosition < BOARD_SIZE; currentPosition++) {
		if ((currentPosition % 3) == 0  && currentPosition != 0) {
			cout << std::endl;
		}
		cout << xCurrentBoard[currentPosition] << " ";
	}
	cout << std::endl;
}

//==DisplayBoard=====================================
//Count tile out of place
// size [IN]		  - 
//==================================================
int countingTilesOutOfPlace(char xBoard[]) {
	int count = 0;
	if (xBoard[0] != '1') count++;
	if (xBoard[1] != '2') count++;
	if (xBoard[2] != '3') count++;
	if (xBoard[3] != '8') count++;
	if (xBoard[4] != 'x') count++;
	if (xBoard[5] != '4') count++;
	if (xBoard[6] != '7') count++;
	if (xBoard[7] != '6') count++;
	if (xBoard[8] != '5') count++;
	return count;
}

void readFromFile(string xFileName, EightGame & xInit) {
	char     board[BOARD_SIZE];
	string   line;
	ifstream myfile(xFileName);

	if (myfile.is_open()) {

		for (int index = 0; index < BOARD_SIZE; index++) {
			board[index] = myfile.get();
			myfile.get();
		}

		myfile.ignore(1,'\n');
		xInit.SetBoard(board);

		for (int index = 0; index < BOARD_SIZE; index++) {
			board[index] = myfile.get();
			myfile.get();
		}

		xInit.SetWinBoard(board);
		myfile.close();
	} else {
		cout << "Unable to open file";
	}
}


