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
enum DIRECTION {UP = 8, LEFT = 4, RIGHT = 6, DOWN = 2};

GameAi::GameAi() {}

//=======NEED TO BE CHANGE==================
bool GameAi::SetGameBoard(EightGame xSetItem)
{
	mCurrentBoard = xSetItem;
	return true;
}


//===CalulateHeuristicOne==========================
// Calculate Heuristic value base on the tile out of
//	position in the board
//	Compare current to the winning state
// Return: 	Heuristic Value:
//	** this does not store the calculate value
//==================================================
int GameAi::CalulateHeuristicOne() {
	int count = 0;

	if (mCurrentBoard.GetBoard()[0] != mCurrentBoard.GetWinBoard()[0]) count++;
	if (mCurrentBoard.GetBoard()[1] != mCurrentBoard.GetWinBoard()[1]) count++;
	if (mCurrentBoard.GetBoard()[2] != mCurrentBoard.GetWinBoard()[2]) count++;
	if (mCurrentBoard.GetBoard()[3] != mCurrentBoard.GetWinBoard()[3]) count++;
	if (mCurrentBoard.GetBoard()[4] != mCurrentBoard.GetWinBoard()[4]) count++;
	if (mCurrentBoard.GetBoard()[5] != mCurrentBoard.GetWinBoard()[5]) count++;
	if (mCurrentBoard.GetBoard()[6] != mCurrentBoard.GetWinBoard()[6]) count++;
	if (mCurrentBoard.GetBoard()[7] != mCurrentBoard.GetWinBoard()[7]) count++;
	if (mCurrentBoard.GetBoard()[8] != mCurrentBoard.GetWinBoard()[8]) count++;
	return count;
}


//===CalulateHeuristicTwo==========================
// Calculate Heuristic value base on how far the tile
//	Is from the correct position
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
		boardMain = mCurrentBoard.FindCharInBoard(mCurrentBoard.GetWinBoard()[index]);

		divBoard = boardMain / 3;
		modBoard = boardMain % 3;

		divWin = index / 3;
		modWin = index % 3;

		count = count + (abs(divBoard-divWin) + abs(modBoard-modWin));
	}
	return count;
}

void GameAi::playGameSteepHillClimb()
{
	while (numSteps < MAX_STEPS)
	{
		//if current state is a solution RETURN
		if (mCurrentBoard.CheckForWin()) return;

		//else generate all possible states
		list<State> stateList = GenerateStateList();

		//Apply heuristics to all states
		for (list<State>::iterator itr = stateList.begin(); itr != stateList.end(); itr++)
		{
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

/*
 * Generates the state list of possible states. Doesn't work yet.
 * Uses the member variable mCurrentState to generate the possible states from
 */
list <State> GameAi::GenerateStateList() {
    list<State> pStateList;
    State 		xNewState;
    EightGame 	xCurrentBoard = this->getCurrentBoard();
    cout << "Did this call correctly?" << endl;
    xCurrentBoard.DisplayBoard();

    list<State>::iterator itr2 = mOrderOfInsertion.begin();

    if (xCurrentBoard.IsMovable(UP)) {
        cout << "Log: UP was called------------" << std::endl;
        EightGame xNewBoard = xCurrentBoard;
        xNewBoard.MoveDirection(UP);
        xNewBoard.DisplayBoard();
        cout << " ------------------------------" << std::endl;
        pStateList.emplace_back(State(xNewBoard));

        mOrderOfInsertion.insert(itr2,xNewState);
    }
    if (xCurrentBoard.IsMovable(DOWN)) {
        EightGame xNewBoard = xCurrentBoard;
        xNewBoard.MoveDirection(DOWN);
        xNewBoard.DisplayBoard();
        cout << " ------------------------------" << std::endl;
        pStateList.emplace_back(State(xNewBoard));

        mOrderOfInsertion.insert(itr2,xNewState);
    }
    if (xCurrentBoard.IsMovable(LEFT)) {
        cout << "Log: LEFT was called ------------" << std::endl;
        EightGame xNewBoard = xCurrentBoard;
        xNewBoard.MoveDirection(LEFT);
        xNewBoard.DisplayBoard();
        cout << " ------------------------------" << std::endl;
        pStateList.emplace_back(State(xNewBoard));

        mOrderOfInsertion.insert(itr2,xNewState);
    }
    if (xCurrentBoard.IsMovable(RIGHT)) {
        cout << "Log: RIGHT was called-------------" << std::endl;
        EightGame xNewBoard = xCurrentBoard;
        xNewBoard.MoveDirection(RIGHT);
        xNewBoard.DisplayBoard();
        cout << " ------------------------------" << std::endl;
        pStateList.emplace_back(State(xNewBoard));

        mOrderOfInsertion.insert(itr2,xNewState);
    }

    return pStateList;
}

void GameAi::setCurrentState(EightGame xCurrent) {
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
    int index = 0;
    //cout << "State222: " <<  mOrderOfInsertion.end() << std::endl;
    for (list<State>::iterator itr =  mOrderOfInsertion.begin(); itr !=  mOrderOfInsertion.end(); itr++) {
        cout << "State: " << index++ << std::endl;
        itr->GetBoardState().DisplayBoard();
    }
}


