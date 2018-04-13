#include "Header.h"

int main() {
	char board[BOARD_SIZE][BOARD_SIZE];
	string winner = "a";
	bool end;

	srand(time(NULL));
	initBoard(board);

	//Game loop
	//do {		
		//AIMove(board);
		setBoardStateAt(board, 2, 3, PLAYER);
		setBoardStateAt(board, 2, 2, PLAYER);
		//setBoardStateAt(board, 3, 3, AI);
		switchAdjacentPieces(board);
		//do
		//{
		//	displayBoard(board);
		//} while (!playerMove(board, getXPos(board), getYPos(board)));

		displayBoard(board);

		//winner = winstateCheck(board, end);

	//} while (!end);

	cout << winner << " has won!\n";

	system("pause");
}