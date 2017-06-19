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


#include "GameAi.h"
enum DIRECTION {UP = 8, LEFT = 4, RIGHT = 6, DOWN = 2, EMPTYSLOT = 'x'};

GameAi::GameAi() {
	numSteps = 0;
}

//=======NEED TO BE CHANGE==================
bool GameAi::SetGameBoard(EightGame xSetItem)
{
	mCurrentBoard = xSetItem;
	return true;
}


//===CalulateHeuristicOne==========================
// Calculate Heuristic value base on the tile out of
//	position in the board
//      AKA: Misplaced Tiles - Admissible 
//	Compare current to the winning state
// Return: 	Heuristic Value:
//	** this does not store the calculate value
//==================================================
int GameAi::CalulateHeuristicOne() {
	int count = 0;

    for (int index = 0; index < 9; index++ ){
        //cout << mCurrentBoard.GetBoard()[index] << endl;
        if(mCurrentBoard.GetBoard()[index] != EMPTYSLOT){
            if (mCurrentBoard.GetBoard()[index] != mCurrentBoard.GetWinBoard()[index]) {
                count++;
            }
        }
    }
	return count;
}


//===CalulateHeuristicTwo==========================
// Calculate Heuristic value base on how far the tile
//	Is from the correct position
//      AKA: Manhattan Distance - Admissible
// Return: 	Heuristic Value:
//	** this does not store the calculations value
//==================================================
int GameAi::CalulateHeuristicTwo() {
	int count = 0;

	int boardMain;

	int divBoard;
	int modBoard;

	int divWin;
	int modWin;

	for (int index = 0; index < 9; index++) {
        if(mCurrentBoard.GetWinBoard()[index] != EMPTYSLOT){
    		boardMain = mCurrentBoard.FindCharInBoard(mCurrentBoard.GetWinBoard()[index]);

    		divBoard = boardMain / 3;
    		modBoard = boardMain % 3;

    		divWin = index / 3;
    		modWin = index % 3;

    		count = count + (abs(divBoard-divWin) + abs(modBoard-modWin));
        }
	}
	return count;
}

//===CalulateHeuristicThree==========================
// Calculate Heuristic value base on each tile out of
//  coloum + out of row
//      AKA: Tile out of row and colume - Admissible
//  Compare current to the winning state
// Return:  Heuristic Value:
//  ** this does not store the calculate value
//==================================================
int GameAi::CalulateHeuristicThree() {
    int count = 0;

    for (int index = 0; index < 9; index++) {
        if(mCurrentBoard.GetWinBoard()[index] != EMPTYSLOT){
            int boardMain = mCurrentBoard.FindCharInBoard(mCurrentBoard.GetWinBoard()[index]);

            if(boardMain / 3 != index / 3){
                count++;
            }

            if(boardMain % 3 != index % 3){
                count++;
            }
        }
    }
    return count;
}

void GameAi::PlayGameSteepHillClimb() {
	while (numSteps < MAX_STEPS) {
		//if current state is a solution RETURN
		if (mCurrentBoard.CheckForWin()) {
			return;
		}
		//else generate all possible states
		list<State> stateList = GenerateStateList();


		//Apply heuristics to all states
		for (list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {
			//Apply the heuristic here
			//if heuristic one is chosen
			// ----  NOTE: Need to do this for every heuristic? 
			// -----       Only doing one for now               
			itr->SetHeuristicValue(CalulateHeuristicOne());
		}

		//Select the BEST state


		//Print the BEST state to out.txt

		//Update the number of steps
		numSteps++;
	}
}

void GameAi::PlayBestFirstSearch() {

}


/*
 * Generates the state list of possible states. Doesn't work yet.
 * Uses the member variable mCurrentState to generate the possible states from
 */
list <State> GameAi::GenerateStateList() {
    list<State> pStateList;
    State 		newState;
    EightGame 	currentBoard = this->GetCurrentBoard();
    //cout << "Did this call correctly?" << endl;
    //currentBoard.DisplayBoard();

    list<State>::iterator itr2 = mOrderOfInsertion.begin();

    if (currentBoard.IsMovable(UP)) {
        cout << "Log: UP was called" << std::endl;
        EightGame newBoard = currentBoard;
        newBoard.MoveDirection(UP);
        //newBoard.DisplayBoard();
        //cout << "------------------------------" << std::endl;
        pStateList.emplace_back(State(newBoard));

        mOrderOfInsertion.emplace_back(State(newBoard));
    }
    if (currentBoard.IsMovable(DOWN)) {
        cout << "Log: DOWN was called" << std::endl;
        EightGame newBoard = currentBoard;
        newBoard.MoveDirection(DOWN);
        //newBoard.DisplayBoard();
        //cout << "------------------------------" << std::endl;
        pStateList.emplace_back(State(newBoard));

        mOrderOfInsertion.emplace_back(State(newBoard));
    }
    if (currentBoard.IsMovable(LEFT)) {
        cout << "Log: LEFT was called" << std::endl;
        EightGame newBoard = currentBoard;
        newBoard.MoveDirection(LEFT);
        //newBoard.DisplayBoard();
        //cout << "------------------------------" << std::endl;
        pStateList.emplace_back(State(newBoard));

        mOrderOfInsertion.emplace_back(State(newBoard));
    }
    if (currentBoard.IsMovable(RIGHT)) {
        cout << "Log: RIGHT was called" << std::endl;
        EightGame newBoard = currentBoard;
        newBoard.MoveDirection(RIGHT);
        //newBoard.DisplayBoard();
        //cout << "------------------------------" << std::endl;
        pStateList.emplace_back(State(newBoard));

        mOrderOfInsertion.emplace_back(State(newBoard));
    }

    return pStateList;
}

void GameAi::SetCurrentState(EightGame xCurrent) {
    mCurrentState.SetBoard(xCurrent);
    mCurrentBoard = xCurrent;
}

//This is just for debugging
void GameAi::PrintList(list <State> xStateList) {
    int index = 0;
    for (list<State>::iterator itr = xStateList.begin(); itr != xStateList.end(); itr++) {
        cout << "State: " << index++ << std::endl;
        itr->GetBoardState().DisplayBoard();
    }
}

void GameAi::PrintLocalList() {
    //int index = 0;
    for(int number = 0 ; number < 3; number++)
    {
    //cout << "State222: " <<  mOrderOfInsertion.end() << std::endl;
        for (list<State>::iterator itr =  mOrderOfInsertion.begin(); 
                itr !=  mOrderOfInsertion.end(); 
                itr++) {
            //cout << "State: " << index++ << std::endl;
            itr->GetBoardState().DisplayBoardAtLine(number);
            cout << "   ";
        }
        cout << endl;

    }
}



