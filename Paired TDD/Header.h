#pragma once
#include <iostream>
#include <string>
using namespace std;

const int BOARD_SIZE = 5;
const char AI = 'X';
const char PLAYER = 'O';

void initBoard(char board[][BOARD_SIZE]);
void displayBoard(char board[][BOARD_SIZE]);
void AIMove();

//Helper functions
inline char getBoardStateAt(char board[][BOARD_SIZE], int xIndex, int yIndex)
{
	return board[xIndex][yIndex];
}

inline void setBoardStateAt(char board[][BOARD_SIZE], int xIndex, int yIndex, char type)
{
	board[xIndex][yIndex] = type;
}

//Brian Features
void playerMove();
void switchAdjacentPieces();

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
