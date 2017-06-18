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


#include "StateGenerator.h"
enum DIRECTION {UP = 8, LEFT = 4, RIGHT = 6, DOWN = 2};

void StateGenerator::setCurrentState(EightGame xCurrent) {
    mCurrentState.SetBoard(xCurrent);
}

/*
 * Generates the state list of possible states. Doesn't work yet.
 * Uses the member variable mCurrentState to generate the possible states from
 */
list <State> StateGenerator::GenerateStateList() {
    list<State> pStateList;
    State 		xNewState;
    EightGame 	xCurrentBoard = mCurrentState.GetBoardState();

    list<State>::iterator itr = pStateList.begin();

    list<State>::iterator itr2 = mOrderOfInsertion.begin();

    if (xCurrentBoard.IsMovable(UP)) {
        cout << "Log: UP was called" << std::endl;
        xNewState.SetBoard(xCurrentBoard);


        xNewState.GetBoardState().MoveDirection(UP);
        //xNewState.GetBoardState().SwapSpace(UP);
        cout << "Log current board: " << std::endl;
        xCurrentBoard.DisplayBoard();
        cout << "Log board after move: " << endl;
        xNewState.GetBoardState().DisplayBoard();
        pStateList.insert(itr,xNewState);

        mOrderOfInsertion.insert(itr2,xNewState);
    }
    if (xCurrentBoard.IsMovable(DOWN)) {
        cout << "Log: DOWN was called" << std::endl;
        xNewState.SetBoard(xCurrentBoard);

        xNewState.GetBoardState().MoveDirection(DOWN);
        //xNewState.GetBoardState().SwapSpace(DOWN);
        pStateList.insert(itr,xNewState);

        xNewState.GetBoardState().DisplayBoard();
        mOrderOfInsertion.insert(itr2,xNewState);
    }
    if (xCurrentBoard.IsMovable(LEFT)) {
        cout << "Log: LEFT was called" << std::endl;
        xNewState.SetBoard(xCurrentBoard);

        xNewState.GetBoardState().MoveDirection(LEFT);
        //xNewState.GetBoardState().SwapSpace(LEFT);
        pStateList.insert(itr,xNewState);

        xNewState.GetBoardState().DisplayBoard();
        mOrderOfInsertion.insert(itr2,xNewState);
    }
    if (xCurrentBoard.IsMovable(RIGHT)) {
        cout << "Log: RIGHT was called" << std::endl;
        xNewState.SetBoard(xCurrentBoard);

        xNewState.GetBoardState().MoveDirection(RIGHT);
        //xNewState.GetBoardState().SwapSpace(RIGHT);
        pStateList.insert(itr,xNewState);

        xNewState.GetBoardState().DisplayBoard();
        mOrderOfInsertion.insert(itr2,xNewState);
    }

    return pStateList;
}

//This is just for debugging
void StateGenerator::PrintList(list <State> xStateList) {
    int index = 0;
    for (list<State>::iterator itr = xStateList.begin(); itr != xStateList.end(); itr++) {
        cout << "State: " << index++ << std::endl;
        itr->GetBoardState().DisplayBoard();
    }
}

void StateGenerator::PrintLocalList() {
    int index = 0;
    //cout << "State222: " <<  mOrderOfInsertion.end() << std::endl;
    for (list<State>::iterator itr =  mOrderOfInsertion.begin(); itr !=  mOrderOfInsertion.end(); itr++) {
        cout << "State: " << index++ << std::endl;
        itr->GetBoardState().DisplayBoard();
    }
}

