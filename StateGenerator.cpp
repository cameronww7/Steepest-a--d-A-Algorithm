//
// Created by justin on 6/17/17.
//

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
    State xNewState;
    EightGame xCurrentBoard = mCurrentState.GetBoardState();
    list<State>::iterator itr = pStateList.begin();

    if (xCurrentBoard.IsMovable(UP)) {
        cout << "Log: UP was called" << endl;
        xNewState.SetBoard(xCurrentBoard);
        xNewState.GetBoardState().SwapSpace(UP);
        cout << "Log current board: " << endl;
        xCurrentBoard.displayBoard();
        cout << "Log board after move: " << endl;
        xNewState.GetBoardState().displayBoard();
        pStateList.insert(itr,xNewState);
    }
    if (xCurrentBoard.IsMovable(DOWN)) {
        cout << "Log: DOWN was called" << endl;
        xNewState.SetBoard(xCurrentBoard);
        xNewState.GetBoardState().SwapSpace(DOWN);
        pStateList.insert(itr,xNewState);
    }
    if (xCurrentBoard.IsMovable(LEFT)) {
        cout << "Log: LEFT was called" << endl;
        xNewState.SetBoard(xCurrentBoard);
        xNewState.GetBoardState().SwapSpace(LEFT);
        pStateList.insert(itr,xNewState);
    }
    if (xCurrentBoard.IsMovable(RIGHT)) {
        cout << "Log: RIGHT was called" << endl;
        xNewState.SetBoard(xCurrentBoard);
        xNewState.GetBoardState().SwapSpace(RIGHT);
        pStateList.insert(itr,xNewState);
    }

    return pStateList;
}

//This is just for debugging
void StateGenerator::PrintList(list <State> xStateList) {
    int i = 0;
    for (list<State>::iterator itr = xStateList.begin(); itr != xStateList.end(); itr++) {
        cout << "State: " << i++ << endl;
        itr->GetBoardState().displayBoard();
    }
}
