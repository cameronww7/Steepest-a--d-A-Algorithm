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


#ifndef STATE_GENERATOR_H
#define STATE_GENERATOR_H

#include <list>
#include "State.h"

/***************************************************************
 * This class will be used to create a list of possible moves
 * given the current state of the board Doesn't work correctly
 * currently.
 **************************************************************/
class StateGenerator {
public:
    list <State> GenerateStateList();
    void         setCurrentState(EightGame xCurrent);
    void         PrintList(list<State> xStateList);

private:
    State mCurrentState;
};


#endif //STATE_GENERATOR_H
