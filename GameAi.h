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
	GameAi();
	EightGame GetCurrentBoard() { return mCurrentBoard;};
	int       GetNumSteps() {return numSteps;};
	bool      SetGameBoard(EightGame xSetItem);
	void      SetCurrentState(EightGame xCurrent);
	void      PrintList(list<State> xStateList);
    void      PrintLocalList();
	int       CalulateHeuristicOne(State state);
	int       CalulateHeuristicTwo(State state);
	int       CalulateHeuristicThree(State state);
	int       PlayGameSteepHillClimb(const int xHeuristicNumber);
	int       PlayBestFirstSearch(const int xHeuristicNumber);
	void      GenerateAMove(EightGame 	& xCurrentBoard,
							list<State>  & xPStateList,
							const int      xDirection);
	void      CleanGameAi();
	list <State> GenerateStateList();

private: 
    enum DIRECTION {UP        = 8,
					LEFT      = 4,
					RIGHT     = 6,
					DOWN      = 2,
					EMPTYSLOT = 'x',
					MAX_COL	  = 5 };

	const int MAX_STEPS       = 100;
	const int BOARD_SIZE      = 9;
	const int BOARD_ROW_SIZE  = 3;

	int numSteps = 0;

	State mCurrentState; 

	list <State> mOrderOfInsertion;

	EightGame mCurrentBoard;
};
