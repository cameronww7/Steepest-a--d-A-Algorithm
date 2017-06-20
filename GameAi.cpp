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
int GameAi::CalulateHeuristicOne(State xState) {
	int count = 0;
	EightGame board = xState.GetBoardState();

    for (int index = 0; index < BOARD_SIZE; index++ ){
        //cout << mCurrentBoard.GetBoard()[index] << endl;
		if (board.GetBoard()[index] != EMPTYSLOT){
			if (board.GetBoard()[index] != board.GetWinBoard()[index]) {
                count++;
            }
        }
    }
	return count + numSteps;
}

//===CalulateHeuristicTwo==========================
// Calculate Heuristic value base on how far the tile
//	Is from the correct position
//      AKA: Manhattan Distance - Admissible
// Return: 	Heuristic Value:
//	** this does not store the calculations value
//==================================================
int GameAi::CalulateHeuristicTwo(State xState) {
	int count = 0;
	EightGame board = xState.GetBoardState();
	int boardMain;

	int divBoard;
	int modBoard;

	int divWin;
	int modWin;

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
	return count + numSteps;
}

//===CalulateHeuristicThree==========================
// Calculate Heuristic value base on each tile out of
//  coloum + out of row
//      AKA: Tile out of row and colume - Admissible
//  Compare current to the winning state
// Return:  Heuristic Value:
//  ** this does not store the calculate value
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
    return count + numSteps;
}

void GameAi::PlayGameSteepHillClimb() {
	cout << endl << "Play Steep-Hill Ascent Climb" << endl;
	numSteps = 0;
	srand(time(NULL));

	while (numSteps < MAX_STEPS && !mCurrentBoard.CheckForWin()) {

		cout << endl << "********************CURRENT BOARD****************************" << endl;
		GetCurrentBoard().DisplayBoard();

		//else generate all possible states
		cout << endl << "+++GENERATING STATE LIST:" << endl;
		std::list<State> stateList = GenerateStateList();
		numSteps++;
		cout << endl;
		//PrintList(stateList);


		//Apply heuristics to all states
		cout << endl << "+++APPLYING HEURISTICS:" << endl << endl;
		/* for Kenny code
		for (std::list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {        
			itr->SetHeuristicValue(CalulateHeuristicOne(*itr));
			itr->DisplayState();

			cout << "Heuristic: " << itr->GetHeuristicValue() << " " << endl << endl;
		}


		cout << endl << "+++SELECTING THE BEST STATE:"<< endl << endl;
		State bestState = stateList.front();
		//bestState.SetHeuristicValue(1000);
		for (list<State>::iterator itr = ++stateList.begin(); itr != stateList.end(); itr++) {
			if (*itr > bestState){
				bestState = *itr;
				//cout << "===" <<bestState.GetHeuristicValue() << endl;
			}
		}
		*/

		//Testing oat
		for (std::list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {        
			itr->SetHeuristicValue(CalulateHeuristicOne(*itr));
			//itr->DisplayState();

			cout << "Heuristic1: " << CalulateHeuristicOne(*itr)<< " " << endl;
		}

		for (std::list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {      
			
			if(itr->GetHeuristicValue() > CalulateHeuristicTwo(*itr))
			{
				itr->SetHeuristicValue(CalulateHeuristicTwo(*itr));
				
			}
			//itr->DisplayState();
			cout << "Heuristic2: " << CalulateHeuristicTwo(*itr) << " " << endl;
		}

		for (std::list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {        
			
			if(itr->GetHeuristicValue() > CalulateHeuristicThree(*itr))
			{
				itr->SetHeuristicValue(CalulateHeuristicThree(*itr));
				
			}
			//itr->DisplayState();
			cout << "Heuristic3: " << CalulateHeuristicThree(*itr) << " " << endl;
		}


		for (list<State>::iterator itr = ++stateList.begin(); itr != stateList.end(); itr++){
			cout << "Heuristic:   ALL  " << endl;
			itr->DisplayState();
			cout << itr->GetHeuristicValue() << endl << endl;
		}

		cout << endl;

		cout << endl << "+++SELECTING THE BEST STATE:"<< endl << endl;
		State bestState = stateList.front();
		bestState.SetHeuristicValue(1000);
		for (list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++) {
			
			if (bestState > *itr){
				bestState.SetHeuristicValue(itr->GetHeuristicValue());
				bestState.SetBoard(itr->GetBoardState());
				bestState.SetOldMove(itr->GetOldMove());

				cout << "===" <<bestState.GetHeuristicValue() << endl;
			}

			else if(bestState == *itr){
				if(rand() % 2){
					bestState.SetHeuristicValue(itr->GetHeuristicValue());
					bestState.SetBoard(itr->GetBoardState());
					bestState.SetOldMove(itr->GetOldMove());

					cout << "rand=" <<bestState.GetHeuristicValue() << endl;
				}

			}

			cout << "++++++++++++" << endl;
			cout << bestState.GetHeuristicValue() << endl;
			cout << itr->GetHeuristicValue() << endl;
		}
		//end oat test


		mCurrentBoard = bestState.GetBoardState();
		mCurrentState.SetOldMove(bestState.GetOldMove());
		mCurrentState.SetBoard(bestState.GetBoardState());
		mCurrentState.DisplayState();
		cout << endl;

		//Print the BEST state to out.txt

		//Update the number of steps
		//numSteps++;
		cout << "Number of steps: " << GetNumSteps() << endl;
	}
}


void GameAi::PlayBestFirstSearch() {
	std::cout << "\nPlay Best-First Search\n";

	std::list<State> openList;
	std::list<State> closeList;
	State x;
	// Counter for path value
	int pathCounter = 0;

	openList.push_front(mCurrentState); // Pushing Root Node Current State

	while (!openList.empty()) {
		// X represents the first state in the open queue
		x = openList.front();
		// If the current board is equal to the winning board, return
		if (x.GetBoardState().GetBoard() == mCurrentBoard.GetWinBoard()) {
			return;
		} else {
			// Generates a list of possible states
			std::list<State> stateList = GenerateStateList();
			pathCounter++;
			// Iterates through state list
			for (list<State>::iterator itr1 = stateList.begin(); itr1 != stateList.end(); itr1++) {
				bool stateIsOnOpenList  = SearchListForCurrentState(*itr1, openList);
				bool stateIsOnCloseList = SearchListForCurrentState(*itr1, closeList);

				if (!stateIsOnOpenList && !stateIsOnCloseList) {
					itr1->SetHeuristicValue(CalulateHeuristicOne(*itr1));
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
					// If the current path we took to this node is shorter than the old path
					if(pathCounter < itr1->GetPathValue()) {
						// Update path counter
						itr1->SetPathValue(pathCounter);
						// Delete from close list
						closeList.remove(*itr1);
						// Add to open list
						openList.push_front(*itr1);
					}
				}
				closeList.push_front(x);
				// Sort the open list
				openList.sort(CompareStateHeuristicValues);
			}
		}
	}
}

void GameAi::GenerateAMove(EightGame & xCurrentBoard, list<State> & xPStateList, const int xDirection) {
    if (xCurrentBoard.IsMovable(xDirection)) {
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
       
       	State newBoard;
       	EightGame newGame;

       	newGame.SetBoard(xCurrentBoard.GetBoard());
       	newGame.SetWinBoard(xCurrentBoard.GetWinBoard());

       	newGame.MoveDirection(xDirection);

       	newBoard.SetBoard(newGame);
        //EightGame newBoard = currentBoard;
        //newBoard.GetBoardState().MoveDirection(xDirection);
       	newBoard.SetOldMove(xDirection);
        //cout << newBoard.GetOldMove() << endl;
        //cout << "------------------------------" << std::endl;
        xPStateList.emplace_back(State(newBoard));
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
    EightGame 	currentBoard;
    currentBoard.SetBoard(this->GetCurrentBoard().GetBoard());
    currentBoard.SetWinBoard(this->GetCurrentBoard().GetWinBoard());
    //cout << "Did this call correctly?" << endl;
    //currentBoard.DisplayBoard();
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

//This is just for debugging
void GameAi::PrintList(list <State> xStateList) {
    int index = 0;
    for (list<State>::iterator itr = xStateList.begin(); itr != xStateList.end(); itr++) {
        cout << "State: " << ++index << std::endl;
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



