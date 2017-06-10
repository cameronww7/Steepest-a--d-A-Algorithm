

const int BOARDSIZE = 9;

class EightGame
{
public:
	EightGame(void){GameBoard[0]=0;};

	char* GetBoard(){return GameBoard;};
	bool SetBoard(char arr[], int size = BOARDSIZE);


private:
	char GameBoard[BOARDSIZE];
};
