#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>   
#include <time.h>      
using namespace std;

const int BOARD_SIZE = 5;
const int PLAY_SIZE = 3;
const char AI = 'X';
const char PLAYER = 'O';

inline void initBoard(char board[][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = '#';
		}
	}
}

void displayBoard(char board[][BOARD_SIZE]);
void AIMove(char board[][BOARD_SIZE]);

//Helper functions
inline char getBoardStateAt(char board[][BOARD_SIZE], int xIndex, int yIndex)
{
	return board[xIndex][yIndex];
}

inline void setBoardStateAt(char board[][BOARD_SIZE], int xIndex, int yIndex, char type)
{
	board[xIndex][yIndex] = type;
}

int getXPos(char board[][BOARD_SIZE]);
int getYPos(char board[][BOARD_SIZE]);

//Brian Features
inline void topLeftCornerCheck(char board[][BOARD_SIZE])
{
	if (getBoardStateAt(board, 1, 1) == PLAYER)
	{
		if (getBoardStateAt(board, 2, 1) == PLAYER)
		{
			setBoardStateAt(board, 3, 1, AI);
		}
		else if (getBoardStateAt(board, 1, 2) == PLAYER)
		{
			setBoardStateAt(board, 1, 3, AI);
		}
		else if (getBoardStateAt(board, 2, 2) == PLAYER)
		{
			setBoardStateAt(board, 3, 3, AI);
		}
	}
}

inline void topRightCornerCheck(char board[][BOARD_SIZE])
{
	if (getBoardStateAt(board, 1, 3) == PLAYER)
	{
		if (getBoardStateAt(board, 1, 2) == PLAYER)
		{
			setBoardStateAt(board, 1, 1, AI);
		}
		else if (getBoardStateAt(board, 2, 2) == PLAYER)
		{
			setBoardStateAt(board, 3, 1, AI);
		}
		else if (getBoardStateAt(board, 2, 3) == PLAYER)
		{
			setBoardStateAt(board, 3, 3, AI);
		}
	}
}

inline void bottomLeftCornerCheck(char board[][BOARD_SIZE])
{
	if (getBoardStateAt(board, 3, 1) == PLAYER)
	{
		if (getBoardStateAt(board, 2, 1) == PLAYER)
		{
			setBoardStateAt(board, 1, 1, AI);
		}
		else if (getBoardStateAt(board, 2, 2) == PLAYER)
		{
			setBoardStateAt(board, 1, 3, AI);
		}
		else if (getBoardStateAt(board, 3, 2) == PLAYER)
		{
			setBoardStateAt(board, 3, 3, AI);
		}
	}
}

inline void bottomRightCornerCheck(char board[][BOARD_SIZE])
{
	if (getBoardStateAt(board, 3, 3) == PLAYER)
	{
		if (getBoardStateAt(board, 2, 3) == PLAYER)
		{
			setBoardStateAt(board, 1, 3, AI);
		}
		else if (getBoardStateAt(board, 3, 2) == PLAYER)
		{
			setBoardStateAt(board, 3, 1, AI);
		}
		else if (getBoardStateAt(board, 2, 2) == PLAYER)
		{
			setBoardStateAt(board, 1, 1, AI);
		}
	}
}

inline void middleCheck(char board[][BOARD_SIZE])
{
	if (getBoardStateAt(board, 2, 2) == PLAYER)
	{
		if (getBoardStateAt(board, 2, 1) == PLAYER)
		{
			setBoardStateAt(board, 2, 3, AI);
		}
		else if (getBoardStateAt(board, 1, 2) == PLAYER)
		{
			setBoardStateAt(board, 3, 2, AI);
		}
		else if (getBoardStateAt(board, 2, 3) == PLAYER)
		{
			setBoardStateAt(board, 2, 1, AI);
		}
		else if (getBoardStateAt(board, 3, 2) == PLAYER)
		{
			setBoardStateAt(board, 1, 2, AI);
		}
	}
}

inline bool playerMove(char board[][BOARD_SIZE], int yIndex, int xIndex)
{
	if(getBoardStateAt(board, xIndex, yIndex) == '#')
	{
		if(xIndex > 0 && xIndex < BOARD_SIZE && yIndex > 0 && yIndex < BOARD_SIZE )
		{
			setBoardStateAt(board, xIndex, yIndex, PLAYER);
			return true;
		}
			cout << "Input out of bounds\n";
	}
	else
	{
		cout << "There is already a peice there\n";
	}

	cout << "Enter different values.\n";
	return false;
}

static int moves[8][2] = { { -1,0 },{ -1, -1 },{ 0, -1 },{ 1, -1 },{ 1, 0 },{ 1, 1 },{ 0, 1 },{ -1, 1 } };

inline bool switchAdjacentPieces(char board[][BOARD_SIZE])
{
	for(int i = 1; i < 4; i++)
	{
		for(int j = 1; j < 4; j++)
		{
			if (getBoardStateAt(board, i, j) == PLAYER)
			{
				for (int l = 0; l < 8; l++)
				{
					if(getBoardStateAt(board, i + moves[l][0], j + moves[l][1]) == PLAYER)
					{
						for (int l = 0; l < 8; l++)
						{
							if (getBoardStateAt(board, i + moves[l][0], j + moves[l][1]) == AI)
							{
								swap(board[i][j], board[i + moves[l][0]][j + moves[l][1]]);
								return true;
							}
						}
					}
				}
			}
		}
	}

	//To see if player is about to win
	topLeftCornerCheck(board);
	topRightCornerCheck(board);
	bottomLeftCornerCheck(board);
	bottomRightCornerCheck(board);

	return false;
}

//Justin Features
inline string winstateCheck(char board[][BOARD_SIZE], bool& end)
{
	end = true;
	return " ";
}

inline bool placeOnBorder(char board[][BOARD_SIZE])
{
	return false;
}
