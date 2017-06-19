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

#include <iostream>
using namespace std;

class EightGame {
public:
	EightGame();

	char * GetBoard() {return mGameBoard;};
	bool   SetBoard(char xArr[]);
	void   DisplayBoard();
	void   DisplayBoardAtLine(int xLevel);
	bool   CheckForWin();

	int    FindEmptySlot();
	int    FindCharInBoard(char xInput);

	bool   MoveDirection(int xDirection);
	bool   IsMovable(int xDirection);
	void   SwapSpace(int xDirection);

	char * GetWinBoard() {return mWinBoard;};
	bool   SetWinBoard(char xArr[]);
	
	//2D array version
	void CreateBoard(int xRows,
					 int xColumns,
					 char xData[]);
	void PrintGameBoard(int xRows,
					    int xColumns);

private:
    enum DIRECTION {UP          = 8,
    		        LEFT        = 4,
				    RIGHT       = 6,
				    DOWN        = 2,
				    EMPTYSLOT   = 'x'};
	static const int BOARD_SIZE = 10; //Size 10 to accommodate the null character
	static const int BOARD_ROW_SIZE  = 3;

	char mGameBoard[BOARD_SIZE];
	char mWinBoard[BOARD_SIZE];

	//2D Game board
	char** m2DGameboard;
};
