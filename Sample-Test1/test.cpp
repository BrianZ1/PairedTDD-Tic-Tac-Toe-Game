#include "pch.h"
#include "../Paired TDD/Header.h"

//Example
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// Winstate Tests
TEST(WinstateCheckTest, horizontalPlayerWinTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	bool end = true;

	initBoard(board);
	setBoardStateAt(board, 1, 1, PLAYER);
	setBoardStateAt(board, 1, 2, PLAYER);
	setBoardStateAt(board, 1, 3, PLAYER);

	string winner = winstateCheck(board, end);

	EXPECT_EQ("Player", winner);
	EXPECT_TRUE(end);
}

TEST(WinstateCheckTest, horizontalAiWinTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	bool end = true;

	initBoard(board);
	setBoardStateAt(board, 1, 1, AI);
	setBoardStateAt(board, 1, 2, AI);
	setBoardStateAt(board, 1, 3, AI);

	string winner = winstateCheck(board, end);

	EXPECT_EQ("AI", winner);
	EXPECT_TRUE(end);
}

TEST(WinstateCheckTest, verticalWinTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	bool end;

	initBoard(board);
	setBoardStateAt(board, 1, 1, AI);
	setBoardStateAt(board, 2, 1, AI);
	setBoardStateAt(board, 3, 1, AI);

	string winner = winstateCheck(board, end);

	EXPECT_EQ("AI", winner);
	EXPECT_TRUE(end);
}

TEST(WinstateCheckTest, diagonalWinTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	bool end;

	initBoard(board);
	setBoardStateAt(board, 1, 1, AI);
	setBoardStateAt(board, 2, 2, AI);
	setBoardStateAt(board, 3, 3, AI);

	string winner = winstateCheck(board, end);

	EXPECT_EQ("AI", winner);
	EXPECT_TRUE(end);
}

TEST(WinstateCheckTest, noWinTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	bool end;

	string winner = winstateCheck(board, end);

	EXPECT_EQ(" ", winner);
	EXPECT_FALSE(end);
}

TEST(WinstateCheckTest, offGridWinTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	bool end;

	initBoard(board);

	setBoardStateAt(board, 0, 0, AI);
	setBoardStateAt(board, 1, 1, AI);
	setBoardStateAt(board, 2, 2, AI);

	string winner = winstateCheck(board, end);

	EXPECT_EQ("AI", winner);
	EXPECT_TRUE(end);
}

//Place off grid tests
TEST(PlaceOffGridTest, twoDifferentAdjacentPieceTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);

	setBoardStateAt(board, 1, 1, AI);
	setBoardStateAt(board, 1, 2, AI);
	setBoardStateAt(board, 2, 1, AI);
	setBoardStateAt(board, 2, 2, AI);

	EXPECT_FALSE(placeOnBorder(board));
}

TEST(PlaceOnBorderTest, placeOnBorderTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);

	setBoardStateAt(board, 1, 1, PLAYER);
	setBoardStateAt(board, 2, 1, AI);
	setBoardStateAt(board, 3, 1, AI);

	EXPECT_TRUE(placeOnBorder(board));
}

//Player Move Tests
TEST(PlayerMoveTest, placeValidTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);

	EXPECT_TRUE(playerMove(board, 1, 1));
	EXPECT_EQ(getBoardStateAt(board, 1, 1), PLAYER);
}

TEST(PlayerMoveTest, placeOnPlayerTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);
	setBoardStateAt(board, 1, 1, PLAYER);

	EXPECT_FALSE(playerMove(board, 1, 1));
}

TEST(PlayerMoveTest, placeOnAITest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);
	setBoardStateAt(board, 1, 1, AI);

	EXPECT_FALSE(playerMove(board, 1, 1));
}

TEST(PlayerMoveTest, placeOffGridTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);

	EXPECT_FALSE(playerMove(board, 0, 0));
}

//Switch Pieces Test
//The function should switch the lowest index of the players winning pair
// with the lowest index of an AI piece adjacent to it.
// if none can be found, block the player pair instead.
TEST(SwitchPiecesTest, switchOnFirstPieceTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);
	setBoardStateAt(board, 1, 1, PLAYER);
	setBoardStateAt(board, 1, 2, PLAYER);
	setBoardStateAt(board, 2, 1, AI);
	setBoardStateAt(board, 2, 2, AI);

	EXPECT_TRUE(switchAdjacentPieces(board));
	EXPECT_EQ(getBoardStateAt(board, 1, 1), AI);
	EXPECT_EQ(getBoardStateAt(board, 2, 1), PLAYER);
}

TEST(SwitchPiecesTest, switchOnSecondPieceTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);
	setBoardStateAt(board, 1, 1, PLAYER);
	setBoardStateAt(board, 1, 2, PLAYER);
	setBoardStateAt(board, 2, 3, AI);

	EXPECT_TRUE(switchAdjacentPieces(board));
	EXPECT_EQ(getBoardStateAt(board, 1, 2), AI);
	EXPECT_EQ(getBoardStateAt(board, 2, 3), PLAYER);
}

TEST(SwitchPiecesTest, switchFailBlockTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);
	setBoardStateAt(board, 1, 1, PLAYER);
	setBoardStateAt(board, 1, 2, PLAYER);
	setBoardStateAt(board, 3, 3, AI);

	EXPECT_FALSE(switchAdjacentPieces(board));
	EXPECT_EQ(getBoardStateAt(board, 1, 3), AI);
}

TEST(CheckGroupsTest, checkRightTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);
	setBoardStateAt(board, 1, 1, PLAYER);
	setBoardStateAt(board, 2, 1, PLAYER);
	setBoardStateAt(board, 3, 1, '#');

	EXPECT_TRUE(checkRight(board, 1, 1, PLAYER, 2));
}

TEST(CheckGroupsTest, checkUpTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);
	setBoardStateAt(board, 1, 1, PLAYER);
	setBoardStateAt(board, 1, 2, PLAYER);
	setBoardStateAt(board, 1, 3, '#');

	EXPECT_TRUE(checkUp(board, 1, 1, PLAYER, 2));
}

TEST(CheckGroupsTest, checkDiagonalTest)
{
	char board[BOARD_SIZE][BOARD_SIZE];

	initBoard(board);
	setBoardStateAt(board, 1, 1, PLAYER);
	setBoardStateAt(board, 2, 2, PLAYER);
	setBoardStateAt(board, 3, 3, '#');

	EXPECT_TRUE(checkDiagonal(board, 1, 1, PLAYER, 2));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}