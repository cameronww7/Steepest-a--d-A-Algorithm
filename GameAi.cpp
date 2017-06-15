
#include <iostream>
#include "GameAi.h"
using namespace std;

//=======NEED TO BE CHANGE==================
bool GameAi::SetGameBoard(EightGame setItem)
{
	m_currentBoard = setItem;
	return true;
}

//==CountingTilesOutOfPlace=====================================
//Count tile out of place
// return - number of tile out of place
//==================================================
int GameAi::CountingTilesOutOfPlace() 
{
	int count = 0;
	if (0 != m_currentBoard.FindCharInBoard('1')) count++;
	if (1 != m_currentBoard.FindCharInBoard('2')) count++;
	if (2 != m_currentBoard.FindCharInBoard('3')) count++;
	if (3 != m_currentBoard.FindCharInBoard('8')) count++;
	if (4 != m_currentBoard.FindCharInBoard('x')) count++;
	if (5 != m_currentBoard.FindCharInBoard('4')) count++;
	if (6 != m_currentBoard.FindCharInBoard('7')) count++;
	if (7 != m_currentBoard.FindCharInBoard('6')) count++;
	if (8 != m_currentBoard.FindCharInBoard('5')) count++;
	return count;
}