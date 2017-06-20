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
const int BOARD_SIZE      = 9;
const int BOARD_ROW_SIZE  = 3;
const int MAX_STEP_COUNT  = 100;
const int HEURISTIC_ONE   = 1;
const int HEURISTIC_TWO   = 2;
const int HEURISTIC_THREE = 3;

int  countingTilesOutOfPlace (char xBoard[]);
void displayBoard (char * xCurrentBoard);
void testGameAndPlay (EightGame * xCurr);
void readFromFile (string      xFileName,
				   EightGame & xInit);

int main() {
	EightGame init;
	State     current;
	GameAi    generator;
	int 	  numberOfSteps;

	readFromFile("input.txt", init);
	std::cout << "Input Board:" << std::endl;
	displayBoard(init.GetBoard());
	std::cout << std::endl << "Goal Board:" << std::endl;
	displayBoard(init.GetWinBoard());
	
	std::cout << "============ Steepest-Ascent Hill-Climbing ============ " << std::endl << std::endl;
	std::cout << "Algorithm: Steepest-Ascent Hill-Climbing" << std::endl << std::endl;

	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	std::cout << "Heuristic: Tile-Out-Of-Place" << std::endl;
	numberOfSteps = generator.PlayGameSteepHillClimb(HEURISTIC_ONE);
	if (numberOfSteps >= MAX_STEP_COUNT) {
		std::cout << "No Solution Found" << std::endl;
	} else {
		std::cout << "Number of Steps: " <<  numberOfSteps << std::endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	std::cout << std::endl;

	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	std::cout << "Heuristic: Number of Move to Correct Position" << endl;
	numberOfSteps = generator.PlayGameSteepHillClimb(HEURISTIC_TWO);
	if (numberOfSteps >= MAX_STEP_COUNT) {
		std::cout << "No Solution Found" << std::endl;
	} else {
		std::cout << "Number of Steps: " <<  numberOfSteps << std::endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	std::cout << std::endl;

	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	std::cout << "Heuristic: Tile out of Column + Tile out of Row" << std::endl;
	numberOfSteps = generator.PlayGameSteepHillClimb(HEURISTIC_THREE);
	if (numberOfSteps >= MAX_STEP_COUNT) {
		std::cout << "No Solution Found" << std::endl;
	} else {
		std::cout << "Number of Steps: " << numberOfSteps << std::endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	std::cout << std::endl << std::endl;

	std::cout << "============ Best-First Search ============ " << std::endl << std::endl;
	std::cout << "Algorithm: Best-First Search" << std::endl;

	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	std::cout << "Heuristic: Tile-Out-Of-Place" << std::endl;
	numberOfSteps = generator.PlayBestFirstSearch(HEURISTIC_ONE);
	if (numberOfSteps >= MAX_STEP_COUNT) {
		std::cout << "No Solution Found" << std::endl;
	} else {
		std::cout << "Number of Steps: " << numberOfSteps << std::endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	std::cout << std::endl;

	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	std::cout << "Heuristic: Number of Move to Correct Position" << std::endl;
	numberOfSteps = generator.PlayBestFirstSearch(HEURISTIC_TWO);
	if (numberOfSteps >= MAX_STEP_COUNT) {
		std::cout << "No Solution Found" << std::endl;
	} else {
		std::cout << "Number of Steps: " << numberOfSteps << std::endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	std::cout << std::endl;

	current.SetBoard(init);
	generator.SetCurrentState(current.GetBoardState());
	std::cout << "Heuristic: Tile out of Column + Tile out of Row" << std::endl;
	numberOfSteps = generator.PlayBestFirstSearch(HEURISTIC_TWO);
	if (numberOfSteps >= MAX_STEP_COUNT) {
		std::cout << "No Solution Found" << std::endl;
	} else {
		std::cout << "Number of Steps: " << numberOfSteps << std::endl;
		generator.PrintLocalList();
	}
	generator.CleanGameAi();
	std::cout << std::endl << std::endl;
	return 0;
}

//==================DisplayBoard=====================
//Display the current game board in 3 X 3 format
//--------------------------------------------------
// IN    : array contain board face value
// IN    : size of the array
// Return: Nothing
//===================================================
void displayBoard(char * xCurrentBoard) {
	for (int currentPosition = 0; currentPosition < BOARD_SIZE; currentPosition++) {
		if ((currentPosition % BOARD_ROW_SIZE) == 0  && currentPosition != 0) {
			std::cout << std::endl;
		}
		std::cout << xCurrentBoard[currentPosition] << " ";
	}
	std::cout << std::endl;
}

//===============readFormFile==========================
//Read a file and put it into an EightGame element
//--------------------------------------------------
// IN    : xFilename - filename that would be open
// IN    : Eight game that will be a container
// Return: returning Eight game container
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
		std::cout << "Unable to open file";
	}
}

//==============testGameAndPlay=====================
//This is use to test/play the game 
//this class can be use to play the actual game
//--------------------------------------------------
// This are just for testing purpose
//--------------------------------------------------
// IN    : xCurr [IN] - EightGame start board
// Return: Nothing
//==================================================
void testGameAndPlay (EightGame * xCurr) {
	int    command;
	char * board = xCurr->GetBoard();

	while (1) { // XX Why is this while(1)? while True?
		displayBoard(board);

		std::cout << "Counting tiles out of place: "
			      << countingTilesOutOfPlace(xCurr->GetBoard())
				  << std::endl << std::endl;

		std::cout << "Enter Direction: ";
		cin >> command; 

		if (command != UP &&
			command != LEFT &&
			command != RIGHT &&
			command != DOWN) {
			std::cout << "Invalid Move" << std::endl << std::endl;
		} else {
			if (xCurr->MoveDirection(command)) {
				std::cout << "good Move" << std::endl;
			} else {
				std::cout << "Invalid Move" << std::endl;
			}

			if (xCurr->CheckForWin()) {
				std::cout << "!!--WINNER--!!" << std::endl;
				displayBoard(board);
				break;
			}
		}
	}
	std::cout << "Exit Game" << std::endl;
}

//===============DisplayBoard========================
//Count tile out of place . This function are used by
// the testGameAndPlay()
//--------------------------------------------------
// This is for testing purpose
//--------------------------------------------------
// xBoard [IN] - element we are looking for
// return 		- number of tile out of place 
//===================================================
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
