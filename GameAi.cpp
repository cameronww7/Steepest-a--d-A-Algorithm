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

namespace {
bool SearchListForCurrentState(std::list<State> stateList,
		                       std::list<State> openList) {
	bool foundStateInList = false; // Used to See if state is on a Queue
	for (list<State>::iterator itr = stateList.begin(); itr != stateList.end() && foundStateInList == false; itr++) {
		if (stateList.front() == openList.front()) {
			foundStateInList = true; // Exit cause found state on queue
		} else {
			openList.pop_front(); // Move to next element
		}
	}
	return foundStateInList;
}
} // Anonymous namespace

GameAi::GameAi() {
	numSteps = 0;
}

//=======NEED TO BE CHANGE==================
bool GameAi::SetGameBoard(EightGame xSetItem) {
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

    for (int index = 0; index < BOARD_SIZE; index++ ){
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

	for (int index = 0; index < BOARD_SIZE; index++) {
        if(mCurrentBoard.GetWinBoard()[index] != EMPTYSLOT){
    		boardMain = mCurrentBoard.FindCharInBoard(mCurrentBoard.GetWinBoard()[index]);

    		divBoard = boardMain / BOARD_ROW_SIZE;
    		modBoard = boardMain % BOARD_ROW_SIZE;

    		divWin = index / BOARD_ROW_SIZE;
    		modWin = index % BOARD_ROW_SIZE;

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

    for (int index = 0; index < BOARD_SIZE; index++) {
        if (mCurrentBoard.GetWinBoard()[index] != EMPTYSLOT) {
            int boardMain = mCurrentBoard.FindCharInBoard(mCurrentBoard.GetWinBoard()[index]);

            if (boardMain / BOARD_ROW_SIZE != (index / BOARD_ROW_SIZE)) {
                count++;
            }

            if (boardMain % BOARD_ROW_SIZE != (index % BOARD_ROW_SIZE)) {
                count++;
            }
        }
    }
    return count;
}

void GameAi::PlayGameSteepHillClimb() {
	cout << endl << "Play Steep-Hill Ascent Climb" << endl;

	while (numSteps < MAX_STEPS) {
		//if current state is a solution RETURN
		if (mCurrentBoard.CheckForWin()) {
			return;
		}
		//else generate all possible states
		cout << endl << "Generating State List" << endl;
		std::list<State> stateList = GenerateStateList();
		PrintList(stateList);


		//Apply heuristics to all states
		cout << endl << "Applying Heuristics to all states" << endl;
		for (std::list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {
			//Apply the heuristic here
			//if heuristic one is chosen
			// ----  NOTE: Need to do this for every heuristic? 
			// -----       Only doing one for now               
			itr->SetHeuristicValue(CalulateHeuristicOne());

			cout << CalulateHeuristicOne() << " ";
		}
		cout << endl;

		//Select the BEST state
		cout << endl << "Selecting the BEST state" << endl;
		State bestState = stateList.front();
		for (list<State>::iterator itr = ++stateList.begin(); itr != stateList.end(); itr++) {
			if (*itr > bestState){
				bestState = *itr;
			}
		}
		mCurrentBoard = bestState.GetBoardState();
		cout << "The best state is " << endl;
		mCurrentBoard.DisplayBoard();
		cout << endl;

		//Print the BEST state to out.txt

		//Update the number of steps
		cout << endl << "Updating number of Steps" << endl;
		numSteps++;
		cout << endl << "Number of steps: " << GetNumSteps() << endl;
	}
}


void GameAi::PlayBestFirstSearch() {
	std::cout << "\nPlay Best-First Search\n";

	std::list<State> openList;
	std::list<State> closeList;
	State x;

	openList.push_front(mCurrentState); // Pushing Root Node Current State

	while (!openList.empty()) {
		// X represents the first state in the open queue
		x = openList.front();
		// If the current board is equal to the winning board, return
		if (x.GetBoardState().GetBoard() == mCurrentBoard.GetWinBoard()) {
			return;
		} else {
			// Generates a list of possible statess
			std::list<State> stateList = GenerateStateList();
			// Iterates through state list
			for (list<State>::iterator itr1 = stateList.begin(); itr1 != stateList.end(); itr1++) {
				bool stateIsNotOnOpenList  = SearchListForCurrentState(stateList, openList);
				bool stateIsNotOnCloseList = SearchListForCurrentState(stateList, closeList);

				if (stateIsNotOnOpenList != true &&
						stateIsNotOnCloseList != true) {
//					stateList.front().CalulateHeuristicOne();
					openList.push_front(stateList.front());
					stateList.pop_front(); // Move to next element
				} else if (stateIsNotOnOpenList == true) {
					// If the child was reached by a shorter path
					// Then give the state on open the shorter path??
				} else if (stateIsNotOnCloseList == true) {
					// If child was reached by shorter path then

					while(stateList.front() == closeList.front()) {
						closeList.pop_front(); // Move to next element
					}
					//remove the element
				}
				closeList.push_front(x);
			}
		}
	}
}

void GameAi::GenerateAMove(EightGame & currentBoard, list<State> & pStateList, const int xDirection) {
    if (currentBoard.IsMovable(xDirection)) {
		switch (xDirection){
			case 8: cout << "Log: UP was called" << std::endl;
				break;
			case 2: cout << "Log: DOWN was called" << std::endl;
				break;
			case 4: cout << "Log: LEFT was called" << std::endl;
				break;
			case 6: cout << "Log: RIGHT was caleld" << std::endl;
			default: return;
		}
       
        EightGame newBoard = currentBoard;
        newBoard.MoveDirection(xDirection);
        //newBoard.DisplayBoard();
        //cout << "------------------------------" << std::endl;
        pStateList.emplace_back(State(newBoard));

        mOrderOfInsertion.emplace_back(State(newBoard));
    }
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

    GenerateAMove(currentBoard, pStateList, UP);
    GenerateAMove(currentBoard, pStateList, DOWN);
    GenerateAMove(currentBoard, pStateList, LEFT);
    GenerateAMove(currentBoard, pStateList, RIGHT);

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
    for (int number = 0 ; number < BOARD_ROW_SIZE; number++) {
    //cout << "State222: " <<  mOrderOfInsertion.end() << std::endl;
        for (list<State>::iterator itr =  mOrderOfInsertion.begin(); itr !=  mOrderOfInsertion.end(); itr++) {
            //cout << "State: " << index++ << std::endl;
            itr->GetBoardState().DisplayBoardAtLine(number);
            cout << "   ";
        }
        cout << endl;
    }
}



