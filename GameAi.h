
#include "EightGame.h"


class GameAi
{
public:


	bool SetGameBoard(EightGame setItem);

	//heuristic
	int CountingTilesOutOfPlace();
private: 
	EightGame m_currentBoard;
};