#include "Header.h"

void initBoard(char board[][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = '#';
		}
	}
}

void displayBoard(char board[][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void AIMove(char board[][BOARD_SIZE]) {
	bool validPlay = false;

	do
	{
		int xPos = rand() % 3 + 1;
		int yPos = rand() % 3 + 1;

		if(getBoardStateAt(board, xPos, yPos) == '#')
		{
			setBoardStateAt(board, xPos, yPos, AI);
			validPlay = true;
		}

	} while (!validPlay);
}