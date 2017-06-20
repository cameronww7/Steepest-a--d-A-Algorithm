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


#ifndef STATE_H
#define STATE_H

#include "EightGame.h"

/****************************************************************
 *  Goal of Class
 *  ------------------------------------------------------------
 *  Represents state of a board at a given time, along with their
 *  heuristic value, with the idea that they be used for the
 *  queues when implementing the search algorithms.
 ***************************************************************/
class State {
public:
    State();
    State(EightGame);

    EightGame GetBoardState() { return  mCurrentBoard;};
    int  	  GetHeuristicValue() {return  mHeuristicValue;};
    int  	  GetOldMove() {return mOldMove;};
	int  	  GetPathValue() {return mPathValue;};
    void 	  SetBoard(EightGame xEGBoard);
    void 	  SetHeuristicValue(int xHValue);
    void 	  SetOldMove(int xDirection) {mOldMove = xDirection;};
	void 	  SetPathValue(int xPathValue) {mPathValue = xPathValue;};
    void 	  DisplayState();

    // Overloaders
	State operator=(const State & xRHS);
	bool  operator==(State & xRHS);
	bool  operator>(State & xRHS);

private:
	const int BOARD_SIZE      = 9;
	const int BOARD_ROW_SIZE  = 3;

    EightGame mCurrentBoard;
    int       mHeuristicValue;
	int 	  mPathValue = 0;
    int 	  mOldMove;
};
#endif
