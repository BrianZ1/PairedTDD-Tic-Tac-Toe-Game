#include "Header.h"

void displayBoard(char board[][BOARD_SIZE]) {
	cout << "  0 1 2 3 4" << endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << i << " ";
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

int getXPos(char board[][BOARD_SIZE])
{
	int x;
	cout << "Enter X coord" << endl;
	cin >> x;
	return x;
}

int getYPos(char board[][BOARD_SIZE])
{
	int y;
	cout << "Enter Y coord" << endl;
	cin >> y;
	return y;
}

