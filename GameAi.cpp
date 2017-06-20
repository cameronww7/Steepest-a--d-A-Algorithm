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


#include "GameAi.h"


namespace {
bool SearchListForCurrentState(State            xState,
		                       std::list<State> xList) {
	bool foundStateInList = false; // Used to See if state is on a Queue
	for (list<State>::iterator itr = xList.begin(); itr != xList.end() && foundStateInList == false; itr++) {
		if (xState == *itr) {
			foundStateInList = true; // Exit cause found state on queue
		} 
	}
	return foundStateInList;
}

bool CompareStateHeuristicValues(State& first, State& second)
{
    return (first.GetHeuristicValue() < second.GetHeuristicValue());
}
} // Anonymous namespace

GameAi::GameAi() {
	numSteps = 0;
}

//=================SetGameBoard=====================
// Sets the game board based on the parameter board
// passed into the function
//-------------------------------------------------
// In    : EightGame xSetItem
// Return: True
//==================================================
bool GameAi::SetGameBoard(EightGame xSetItem) {
	mCurrentBoard = xSetItem;
	return true;
}

//=============CalulateHeuristicOne=================
// Calculate Heuristic value base on the tile out of
//	position in the board
//      AKA: Misplaced Tiles - Admissible 
//-------------------------------------------------
// In    : State xState
// Return: Heuristic Value
//==================================================
int GameAi::CalulateHeuristicOne(State xState) {
	int count = 0;
	EightGame board = xState.GetBoardState();

    for (int index = 0; index < BOARD_SIZE; index++ ) {
        //cout << mCurrentBoard.GetBoard()[index] << endl;
		if (board.GetBoard()[index] != EMPTYSLOT){
			if (board.GetBoard()[index] != board.GetWinBoard()[index]) {
                count++;
            }
        }
    }
    
    int temp;
	if (xState.GetPathValue() != 0) {
		temp = xState.GetPathValue();
	} else {
		temp = numSteps;
	}
	return count + temp;
}

//=============CalulateHeuristicTwo=================
// Calculate Heuristic value base on how far the 
// tile is from the correct position
//      AKA: Manhattan Distance - Admissible 
//-------------------------------------------------
// In    : State xState
// Return: Heuristic Value
//==================================================
int GameAi::CalulateHeuristicTwo(State xState) {
	EightGame board = xState.GetBoardState();
	int boardMain;
	int divBoard;
	int modBoard;
	int divWin;
	int modWin;
	int count = 0;

	for (int index = 0; index < BOARD_SIZE; index++) {
		if (board.GetWinBoard()[index] != EMPTYSLOT){
			boardMain = board.FindCharInBoard(board.GetWinBoard()[index]);

    		divBoard = boardMain / BOARD_ROW_SIZE;
    		modBoard = boardMain % BOARD_ROW_SIZE;

    		divWin = index / BOARD_ROW_SIZE;
    		modWin = index % BOARD_ROW_SIZE;

    		count = count + (abs(divBoard-divWin) + abs(modBoard-modWin));
        }
	}
	
	int temp;
	if (xState.GetPathValue() != 0) {
		temp = xState.GetPathValue();
	} else {
		temp = numSteps;
	}
	return count + temp;
}

//=============CalulateHeuristicThree=================
// Calculate Heuristic value base on the tile out of
// column + out of row
//      AKA: Tile out of row and column - Admissible
//-------------------------------------------------
// In    : State xState
// Return: Heuristic Value
//==================================================
int GameAi::CalulateHeuristicThree(State xState) {
    int count = 0;
	EightGame board = xState.GetBoardState();

    for (int index = 0; index < BOARD_SIZE; index++) {
		if (board.GetWinBoard()[index] != EMPTYSLOT) {
			int boardMain = board.FindCharInBoard(board.GetWinBoard()[index]);

            if (boardMain / BOARD_ROW_SIZE != (index / BOARD_ROW_SIZE)) {
                count++;
            }
            if (boardMain % BOARD_ROW_SIZE != (index % BOARD_ROW_SIZE)) {
                count++;
            }
        }
    }
    
    int temp;
	if (xState.GetPathValue() != 0) {
		temp = xState.GetPathValue();
	} else {
		temp = numSteps;
	}
	return count + temp;
}

int GameAi::PlayGameSteepHillClimb(int xHeuristicNumber) {
	numSteps = 0;
	srand(time(NULL));

	while (numSteps < MAX_STEPS && !mCurrentBoard.CheckForWin()) {
		//GENERATING STATE LIST
		std::list<State> stateList = GenerateStateList();
		numSteps++;

		//Apply heuristics to all states
		if(xHeuristicNumber == 1){
			for (std::list<State>::iterator itr = stateList.begin(); 
					itr != stateList.end(); 
					itr++) {        
				itr->SetHeuristicValue(CalulateHeuristicOne(*itr));;
			}
		}
		else if (xHeuristicNumber == 2){
			for (std::list<State>::iterator itr = stateList.begin(); 
					itr != stateList.end();
					itr++) {      
					itr->SetHeuristicValue(CalulateHeuristicTwo(*itr));
			}
		}
		else if (xHeuristicNumber == 3){
			for (std::list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {
					itr->SetHeuristicValue(CalulateHeuristicThree(*itr));
			}
		}

		//SELECTING THE BEST STATE
		State bestState = stateList.front();
		bestState.SetHeuristicValue(1000);
		for (list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {
			
			if (bestState > *itr){
				bestState.SetHeuristicValue(itr->GetHeuristicValue());
				bestState.SetBoard(itr->GetBoardState());
				bestState.SetOldMove(itr->GetOldMove());
			}

			else if(bestState == *itr){
				if(rand() % 2){
					bestState.SetHeuristicValue(itr->GetHeuristicValue());
					bestState.SetBoard(itr->GetBoardState());
					bestState.SetOldMove(itr->GetOldMove());
				}

			}
		}//end for loop

		//Update the current State
		mCurrentBoard = bestState.GetBoardState();
		mCurrentState.SetOldMove(bestState.GetOldMove());
		mCurrentState.SetBoard(bestState.GetBoardState());

		//push into the list
		mOrderOfInsertion.push_back(mCurrentState);
		
	}//End While

	return GetNumSteps();
}//End Function


int GameAi::PlayBestFirstSearch(const int xHeuristicNumber) {
	//std::cout << "\nPlay Best-First Search\n";

	std::list<State> openList;
	std::list<State> closeList;
	State x;
	// Counter for path value
	int pathCounter = 0;
	int currentPathValue = 0;
	int counter = 0;

	openList.push_front(mCurrentBoard); // Pushing Root Node Current State

	while (!openList.empty() && !mCurrentBoard.CheckForWin() && counter < MAX_STEPS) {
		// Assign the first value from open list into X and remove it from the open list
		x.SetBoard(openList.front().GetBoardState());
		openList.pop_front();
		// Generates a list of possible states
		//cout << "Generating a list of all possible states" << endl;
		std::list<State> stateList = GenerateStateList();
		counter++;

		pathCounter++;
		// Iterates through state list
		for (list<State>::iterator itr1 = stateList.begin(); itr1 != stateList.end(); itr1++) {
			bool stateIsOnOpenList  = SearchListForCurrentState(*itr1, openList);
			bool stateIsOnCloseList = SearchListForCurrentState(*itr1, closeList);
			itr1->SetPathValue(pathCounter);
			// Visiting a node that we've never encountered before
			if (!stateIsOnOpenList && !stateIsOnCloseList) {

				//Apply heuristics to all states
				if(xHeuristicNumber == 1) {
					itr1->SetHeuristicValue(CalulateHeuristicOne(*itr1));;
				} else if (xHeuristicNumber == 2) {
					itr1->SetHeuristicValue(CalulateHeuristicTwo(*itr1));
				} else if (xHeuristicNumber == 3) {
					itr1->SetHeuristicValue(CalulateHeuristicThree(*itr1));
				}

				// assigns the path value to the current state
				itr1->SetPathValue(pathCounter);
				openList.push_front(*itr1);

			} else if (stateIsOnOpenList) {
				// If the current path we took to this node is shorter than the old path
				if(pathCounter < itr1->GetPathValue()) {
					// Update path counter
					itr1->SetPathValue(pathCounter);
				}
				
			} else if (stateIsOnCloseList) {
				currentPathValue = itr1->GetPathValue();
				// If the current path we took to this node is shorter than the old path
				if(pathCounter < currentPathValue) {
					// Update path counter
					itr1->SetPathValue(pathCounter);
					// Delete from close list
					/*
					for (list<State>::iterator itr1 = openList.begin(); itr1 != openList.end(); itr1++) {
						itr1->DisplayState();
					}
					*/
					closeList.erase(itr1);
					// Add to open list
					openList.push_front(*itr1);
				}
			}
		}
		// Push the element to the closed list
		closeList.push_front(x);
		// Sort the open list
		openList.sort(CompareStateHeuristicValues);
		// Update the current board
		//openList.front().DisplayState();
		mCurrentBoard.SetBoard(openList.front().GetBoardState().GetBoard());
		State bestState = openList.front();
		//bestState.DisplayState();
		mCurrentState.SetOldMove(bestState.GetOldMove());
		mCurrentState.SetBoard(bestState.GetBoardState());
		mOrderOfInsertion.push_back(mCurrentState);
	}//End  While
	return counter;
}

void GameAi::GenerateAMove(EightGame & xCurrentBoard, list<State> & xPStateList, const int xDirection) {
    if (xCurrentBoard.IsMovable(xDirection)) {
    	/*
		switch (xDirection){
			case 8: cout << "Log: UP was called" << std::endl;
				break;
			case 2: cout << "Log: DOWN was called" << std::endl;
				break;
			case 4: cout << "Log: LEFT was called" << std::endl;
				break;
			case 6: cout << "Log: RIGHT was called" << std::endl;
				break;
			default: return;
		}
		*/
       	State newBoard;
       	EightGame newGame;

       	newGame.SetBoard(xCurrentBoard.GetBoard());
       	newGame.SetWinBoard(xCurrentBoard.GetWinBoard());
       	newGame.MoveDirection(xDirection);

       	newBoard.SetBoard(newGame);
       	newBoard.SetOldMove(xDirection);
        xPStateList.emplace_back(State(newBoard));
    }
}

/*******************************************************************
 * Generates the state list of possible states. Doesn't work yet.
 * Uses the member variable mCurrentState to generate the possible
 * states from
 ******************************************************************/
list <State> GameAi::GenerateStateList() {
    list<State> pStateList;
    State 		newState;
    EightGame 	currentBoard;
    currentBoard.SetBoard(this->GetCurrentBoard().GetBoard());
    currentBoard.SetWinBoard(this->GetCurrentBoard().GetWinBoard());

    int old = mCurrentState.GetOldMove();

    //if to prevent to revers the move
    if(old != DOWN) {
    	GenerateAMove(currentBoard, pStateList, UP);
    }
    if(old != UP) {
    	GenerateAMove(currentBoard, pStateList, DOWN);
    }
    if(old != RIGHT) {
    	GenerateAMove(currentBoard, pStateList, LEFT);
    }
    if(old != LEFT) {
    	GenerateAMove(currentBoard, pStateList, RIGHT);
    }

    return pStateList;
}

void GameAi::SetCurrentState(EightGame xCurrent) {
    mCurrentState.SetBoard(xCurrent);
    mCurrentBoard = xCurrent;
}


void GameAi::CleanGameAi() {
	mOrderOfInsertion.clear();
	numSteps = 0;
	mCurrentState.SetOldMove(0);
}

//This is just for debugging
void GameAi::PrintList(list <State> xStateList) {
    int index = 0;
    for (list<State>::iterator itr = xStateList.begin(); itr != xStateList.end(); itr++) {
        cout << "State: " << ++index << std::endl;
        itr->GetBoardState().DisplayBoard();
    }
}

//====PrintLocalList===========================
//Print the List horizontally
//===========================================
void GameAi::PrintLocalList() {
	list<State> tempList;

    for (list<State>::iterator itrCol = mOrderOfInsertion.begin();
    		itrCol != mOrderOfInsertion.end();
    		){

    	//Create list of 5 element
    	for(int index = 0; index < MAX_COL; index++)
    	{
    		tempList.emplace_back(*itrCol);
    		itrCol++;
    		if(itrCol == mOrderOfInsertion.end()){
    			index = MAX_COL;
    		}

    	}

		for (int number = 0 ; number < BOARD_ROW_SIZE; number++) {
	        for (list<State>::iterator itr =  tempList.begin(); itr !=  tempList.end(); itr++) {
	            itr->GetBoardState().DisplayBoardAtLine(number);
	            cout << "   ";
	        }
	        cout << endl;
    	}
    	tempList.clear();
    	cout << endl;
    }
}
