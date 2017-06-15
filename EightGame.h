
//Size 10 to accomodate the null character
const int BOARDSIZE = 10;
const int LEFT = 4;
const int RIGHT = 6;
const int UP = 8;
const int DOWN = 2;

class EightGame
{
public:
	EightGame(void){m_GameBoard[0]=0;};

	char* GetBoard(){return m_GameBoard;};
	bool SetBoard(char arr[], int size = BOARDSIZE);
	bool CheckForWin();
	int FindEmptySlot();

	void SwapSpace(int direction);
	bool MoveDirection(int direction);
	bool IsMovable(int direction);

private:
	char m_GameBoard[BOARDSIZE];
};
