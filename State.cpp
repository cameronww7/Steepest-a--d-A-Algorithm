//
// Created by justin on 6/17/17.
//

#include "State.h"

State::State() {
    mHeuristicValue = 0;
}

State::State(EightGame xEGBoard) {
    mHeuristicValue = 0;
    mBoardState = xEGBoard;
}


void State::SetBoard(EightGame xEGBoard) {
    mBoardState = xEGBoard;

}

void State::SetHeuristicValue(int xHValue) {
    mHeuristicValue = xHValue;
}


//===CalulateHeuristicOne==========================
// Calulate Heruistic value base on the tile out of
//	position in the board
//	Compare current to the winning state
// Return: 	Heruistic Value:
//	** this does not store the cal value
//==================================================
int State::CalulateHeuristicOne(){
	int count = 0;
	if (mBoardState.GetBoard()[0] != mBoardState.GetWinBoard()[0]) count++;
	if (mBoardState.GetBoard()[1] != mBoardState.GetWinBoard()[1]) count++;
	if (mBoardState.GetBoard()[2] != mBoardState.GetWinBoard()[2]) count++;
	if (mBoardState.GetBoard()[3] != mBoardState.GetWinBoard()[3]) count++;
	if (mBoardState.GetBoard()[4] != mBoardState.GetWinBoard()[4]) count++;
	if (mBoardState.GetBoard()[5] != mBoardState.GetWinBoard()[5]) count++;
	if (mBoardState.GetBoard()[6] != mBoardState.GetWinBoard()[6]) count++;
	if (mBoardState.GetBoard()[7] != mBoardState.GetWinBoard()[7]) count++;
	if (mBoardState.GetBoard()[8] != mBoardState.GetWinBoard()[8]) count++;
	return count;
}


//===CalulateHeuristicTwo==========================
// Calulate Heruistic value base on how far the tile
//	Is from the correct position
// Return: 	Heruistic Value:
//	** this does not store the cal value
//==================================================
int State::CalulateHeuristicTwo(){
	int count = 0;
	int temp;

	for(index = 0; index < Board_Size; index++)
	{
		//index store correct tile number
		//temp store the current tile the number is in
		temp = mBoardState.FindCharInBoard(mBoardState.GetWinBoard()[index]);

		if(temp != index){
			if((temp - index) == 1){
				if(mBoardState.IsMovable(RIGHT)) count++;
				else count = count + 3;
			}
			else if (temp - index ==  -1){
				if(mBoardState.IsMovable(LEFT)) count++;
				else count = count + 3;
			}
			else if(abs(temp - index) == 2){
				count = count + 2;
			}
			else if(abs(temp - index) == 3){
				count++;
			}
			else if(abs(temp - index) == 4){
				count = count + 2;
			}
			else if(abs(temp - index) == 5){
				count = count + 3;
			}
			else if(abs(temp - index) == 8){
				count = count + 4;
			}
			else if(abs(temp - index) == 4){
				count = count + 2;
			}



		}




	}



	return count;
}