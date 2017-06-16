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


#include "EightGame.h"
#include <iostream>
using namespace std;

class GameAi
{
public:

	bool SetGameBoard (EightGame xSetItem);

	//heuristic
	int CountingTilesOutOfPlace ();
private: 
	EightGame mCurrentBoard;
};