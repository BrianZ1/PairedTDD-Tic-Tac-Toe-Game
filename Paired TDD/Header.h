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

void initBoard(char board[][BOARD_SIZE]);
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

//Brian Features
inline bool playerMove(char board[][BOARD_SIZE], int xIndex, int yIndex)
{
	setBoardStateAt(board, xIndex, yIndex, PLAYER);
	return true;
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
