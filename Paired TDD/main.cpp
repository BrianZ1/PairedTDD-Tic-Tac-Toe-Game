#include "Header.h"

int main() {
	char board[BOARD_SIZE][BOARD_SIZE];
	initBoard(board);

	//Game loop
	do {

		board[1][1] = PLAYER;
		board[1][2] = AI;

		displayBoard(board);
	} while (winstateCheck());

	system("pause");
}