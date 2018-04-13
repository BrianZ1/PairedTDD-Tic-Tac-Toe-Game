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

inline bool switchAdjacentPieces(char board[][BOARD_SIZE])
{
	return true;
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
