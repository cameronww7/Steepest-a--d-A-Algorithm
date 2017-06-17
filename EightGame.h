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
	EightGame			   ();

	char * GetBoard        (){return mGameBoard;};     
	void   SwapSpace       (int xDirection);
	bool   SetBoard        (char xArr[]);
	bool   CheckForWin     ();
	bool   MoveDirection   (int xDirection);
	bool   IsMovable       (int xDirection);
	int    FindEmptySlot   ();
	int    FindCharInBoard (char xInput);
<<<<<<< HEAD
	char * GetWinBoard     (){return mWinBoard;};
	bool   SetWinBoard     (char xArr[]);

=======
	void   displayBoard();
>>>>>>> ed7aa3b51a287891c12d01cde476c6ac8efcd70a
	
	//2D array version
	void createBoard(int rows, int columns, char data[]);
	void printGameBoard(int rows, int columns);

private:
	static const int BOARD_SIZE = 10; //Size 10 to accommodate the null character
	static const int LEFT       = 4;
	static const int RIGHT      = 6;
	static const int UP         = 8;
	static const int DOWN       = 2;

	char mGameBoard[BOARD_SIZE];
	char mWinBoard[BOARD_SIZE];

	//2D Game board
	char** gameboard;
};
