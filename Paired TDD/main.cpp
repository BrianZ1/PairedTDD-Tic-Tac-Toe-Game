#include "Header.h"

int main() {
	char board[BOARD_SIZE][BOARD_SIZE];
	string winner = "a";
	bool end;
	initBoard(board);

	//Game loop
	do {

		setBoardStateAt(board, 1, 1, PLAYER);
		setBoardStateAt(board, 1, 2, AI);

		displayBoard(board);

		winner = winstateCheck(board, end);

	} while (!end);

	cout << winner << " has won!\n";

	system("pause");
}