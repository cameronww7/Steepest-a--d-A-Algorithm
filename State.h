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

    EightGame GetBoardState		() { return  mCurrentBoard;};
    void SetBoard             	(EightGame);
    void SetHeuristicValue    	(int);
    int  GetHeuristicValue		() {return  mHeuristicValue;};

    void DisplayState           ();

    // Tile Out Of Position
    int  CalulateHeuristicOne	();
    // How Far the Tile
    int  CalulateHeuristicTwo	();
    // Out of Colume and Row
    //int  CalulateHeuristicThree ();

private:
    EightGame mCurrentBoard;
    int       mHeuristicValue;
};


#endif
