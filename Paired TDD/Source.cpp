#include "Header.h"

void initBoard(char board[][BOARD_SIZE]) {
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) 
		{
			board[i][j] = '#';
		}
	}

}

void displayBoard(char board[][BOARD_SIZE]) {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void AIMove() {

}