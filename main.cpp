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


#include <iostream>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "GameAi.h"
using namespace std;

enum DIRECTION {UP        = 8,
		        LEFT      = 4,
			    RIGHT     = 6,
			    DOWN      = 2,
			    EMPTYSLOT = 'x'};
const int BOARD_SIZE = 9;
const int BOARD_ROW_SIZE = 3;
const int MAX_STEP_COUNT = 100;
const int HEURISTIC_ONE = 1;
const int HEURISTIC_TWO = 2;
const int HEURISTIC_THREE = 3;

void displayBoard (char * xCurrentBoard);

//This is use to test/play the game
void testGameAndPlay (EightGame * xCurr);

//Heuristic function: Counting tiles out of place
int countingTilesOutOfPlace (char xBoard[]);

void readFromFile (string      xFileName,
				   EightGame & xInit);

int main() {
	EightGame init;
	State     current;
	GameAi    generator;
	//GameAi mainAi;
	readFromFile("input.txt", init);

	//Just testing stuff out here
	cout << "Input Board:" << endl;
	displayBoard(init.GetBoard());
	cout << endl << "Goal Board:" << endl;
	displayBoard(init.GetWinBoard());
	

	//Start on Steepest-Ascent Hill-Climbin
	cout << "============ Steepest-Ascent Hill-Climbing ============ " << endl << endl;
	int out;
	
	cout << "Algorithm: Steepest-Ascent Hill-Climbing" << endl << endl;

	//Heuristic One - SAHC
	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	cout << "Heuristic: Tile-Out-Of-Place" << endl;
	out = generator.PlayGameSteepHillClimb(HEURISTIC_ONE);
	if(out >= MAX_STEP_COUNT){
		cout << "No Solution Found" << endl;
	}
	else{
		cout << "Number of Steps: " <<  out << endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	cout << endl;

	
	//Heuristic Twp - SAHC
	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	cout << "Heuristic: Number of Move to Correct Position" << endl;
	out = generator.PlayGameSteepHillClimb(HEURISTIC_TWO);
	if(out >= MAX_STEP_COUNT){
		cout << "No Solution Found" << endl;
	}
	else{
		cout << "Number of Steps: " <<  out << endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	cout << endl;

	//Heuristic Three - SAHC
	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	cout << "Heuristic: Tile out of Column + Tile out of Row" << endl;
	out = generator.PlayGameSteepHillClimb(HEURISTIC_THREE);
	if(out >= MAX_STEP_COUNT){
		cout << "No Solution Found" << endl;
	}
	else{
		cout << "Number of Steps: " << out << endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	cout << endl << endl;

	//Start Best-First Search
	cout << "============ Best-First Search ============ " << endl << endl;

	cout << "Algorithm: Best-First Search" << endl;

	//Heuristic One - BFS
	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	cout << "Heuristic: Tile-Out-Of-Place" << endl;
	out = generator.PlayBestFirstSearch(HEURISTIC_ONE);
	if(out >= MAX_STEP_COUNT){
		cout << "No Solution Found" << endl;
	}
	else{
		cout << "Number of Steps: " << out << endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	cout << endl;

	//Heuristic Two - BFS
	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	cout << "Heuristic: Number of Move to Correct Position" << endl;
	out = generator.PlayBestFirstSearch(HEURISTIC_TWO);
	if(out >= MAX_STEP_COUNT){
		cout << "No Solution Found" << endl;
	}
	else{
		cout << "Number of Steps: " << out << endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	cout << endl;

	//Heuristic Three - BFS
	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	cout << "Heuristic: Tile out of Column + Tile out of Row" << endl;
	out = generator.PlayBestFirstSearch(HEURISTIC_TWO);
	if(out >= MAX_STEP_COUNT){
		cout << "No Solution Found" << endl;
	}
	else{
		cout << "Number of Steps: " << out << endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	cout << endl;

	cout << std::endl;
	//system("PAUSE");
	return 0;
}

//==DisplayBoard=====================================
//Display the current game board in 3 X 3 format
// currentBoard [IN]  - array contain board face value
// size [IN]		  - size of the array
//==================================================
void displayBoard(char * xCurrentBoard) {
	for (int currentPosition = 0; currentPosition < BOARD_SIZE; currentPosition++) {
		if ((currentPosition % BOARD_ROW_SIZE) == 0  && currentPosition != 0) {
			cout << std::endl;
		}
		cout << xCurrentBoard[currentPosition] << " ";
	}
	cout << std::endl;
}

//====readFormFile=====================================
//Read a file and put it into an EightGame element
// xFilename [IN] - filename that would be open
// xInit [IN/OUT] - Eight game that will be a 
//					container for what coming in
//=====================================================
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

//====testGameAndPlay==========================
//This is use to test/play the game 
//this class can be use to play the actuall game
// This are just for testing purpose
// xCurr [IN] - EightGame start board
//============================================
void testGameAndPlay (EightGame * xCurr) {
	int command;
	char * board = xCurr->GetBoard();

	while (1) { // XX Why is this while(1)? while True?
		displayBoard(board);

		cout << "Counting tiles out of place: " 
			<< countingTilesOutOfPlace(xCurr->GetBoard()) << std::endl << std::endl;

		cout << "Enter Direction: ";
		cin >> command; 

		if (command != UP &&
			command != LEFT &&
			command != RIGHT &&
			command != DOWN) {
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
//Count tile out of place . This function are used by
// the testGameAndPlay() for testing purpose
// xBoard [IN] - element we are looking for
// return 		- number of tile out of place 
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
