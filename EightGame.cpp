#include <iostream>
using namespace std;
#include "eightGame.h"


bool EightGame::SetBoard(char  arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		GameBoard[i] = arr[i];
	}
	return true;
}