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


#include "State.h"
#include <iostream>
#include <list>
using namespace std;

class GameAi {
public:

	GameAi();

	bool SetGameBoard (EightGame xSetItem);

    // Tile Out Of Position
    int  CalulateHeuristicOne	();
    // How Far the Tile
    int  CalulateHeuristicTwo	();
    // tile out of column and row separately
    int  CalulateHeuristicThree	();
	//Start here
	void PlayGameSteepHillClimb();

	void PlayBestFirstSearch ();
	// List of states
	list <State> GenerateStateList();
	// Sets the current state
    void         SetCurrentState(EightGame xCurrent);
	//Return current board
	EightGame	 GetCurrentBoard() { return mCurrentBoard;};
	// Print functions for lists
    void         PrintList(list<State> xStateList);
    void 		 PrintLocalList();

private: 
	const int MAX_STEPS = 100;
	int numSteps;
	// State object representing Current state
	State mCurrentState;
	// List containing the order of insertion 
    list <State> mOrderOfInsertion;
	// Eightgame object representing the current board 
	EightGame mCurrentBoard;
};
