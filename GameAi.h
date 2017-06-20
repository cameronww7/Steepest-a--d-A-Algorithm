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


#include "State.h"
#include <iostream>       // std::cin, std::cout
#include <list>			  // std::list
#include <queue>          // std::queue
#include <ctime>
using namespace std;
 /****************************************************************
 *  GameAi
 *  ------------------------------------------------------------
 *  Represents the GameAi that applies heuristic functions and 
 *  algorithms to the 8-puzzle problem
 ***************************************************************/
class GameAi {
public:
	// Default constructor
	GameAi();

	// Sets the game board using EightGame object
	bool SetGameBoard(EightGame xSetItem);

	// The number of steps taken
	int GetNumSteps() {return numSteps;};

    // Tile Out Of Position
    int  CalulateHeuristicOne(State state);

    // How Far the Tile
    int  CalulateHeuristicTwo(State state);

    // Tile out of column and row separately
    int  CalulateHeuristicThree(State state);

	// Steepest-ascent/descent hill-climbing algorithm
	int PlayGameSteepHillClimb(const int xHeuristicNumber);

	// A* Best First Search algorithm
	int PlayBestFirstSearch(const int xHeuristicNumber);

	// Generates an move on the 8-puzzle (EightGame) board
	void GenerateAMove(EightGame 	& xCurrentBoard,
				   	   list<State>  & xPStateList,
					   const int      xDirection);
	// List of states
	list <State> GenerateStateList();

	// Sets the current state
    void         SetCurrentState(EightGame xCurrent);

	//Return current board
	EightGame	 GetCurrentBoard() { return mCurrentBoard;};

	// Resets the GameAi 
    void 		 CleanGameAi();

	// Print functions for lists
    void         PrintList(list<State> xStateList);
    void 		 PrintLocalList();

private: 
	// Numbers representing direction of move on the puzzle board
    enum DIRECTION {UP        = 8,
    		        LEFT      = 4,
				    RIGHT     = 6,
				    DOWN      = 2,
				    EMPTYSLOT = 'x',
					MAX_COL	  = 5 };
	// Maximum steps allowed when attempting to find solution for puzzle problem
	const int MAX_STEPS       = 100;
	// Size of the board for puzzle problem
	const int BOARD_SIZE      = 9;
	// Size of the row for puzzle problem (3x3 board)
	const int BOARD_ROW_SIZE  = 3;

	int numSteps = 0;
	// State object representing Current state
	State mCurrentState;
	// List containing the order of insertion 
    list <State> mOrderOfInsertion;
	// Eightgame object representing the current board 
	EightGame mCurrentBoard;
};
