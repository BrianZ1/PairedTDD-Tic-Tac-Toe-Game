#pragma once
#include <iostream>
using namespace std;

const int BOARD_SIZE = 5;
const char AI = 'X';
const char PLAYER = 'O';

void initBoard(char board[][BOARD_SIZE]);
void displayBoard(char board[][BOARD_SIZE]);
void AIMove();

//Brian Features
void playerMove();
void switchAdjacentPieces();

//Justin Features
inline bool winstateCheck() { return false; };
void placeOffGrid();
