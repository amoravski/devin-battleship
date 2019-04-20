#include "Board.h"

Board::Board()
{
	Ship p;
	for (int i = 0; i < Row; i++)
	{
		for (int k = 0; k < Col; k++)
		{
			board[i][k] = 0;
		}
	}
}

Board::~Board()
{
}

bool Board::CanPlace(Ship &inputed)
{	
	int inputedX = inputed.getX();
	int inputedY = inputed.getY();
	char inputedRot = inputed.getRot();
	int inputedSize = inputed.getSize();

	if (inputedX == 0 || inputedY == 0
		|| (inputedX + inputedSize) > Row - 1 || (inputedY + inputedSize) > Col - 1)
	{
		return false;
	}

	if (inputedRot == 'r')
	{
		for (int i = 0; i < inputedSize; i++)
		{
			if (!board[inputedY][inputedX + i])
			{
				return false;
			}
		}
		shipsOnBoard.push_back(inputed);
		for (int i = 0; i < inputedSize; i++)
		{
			board[inputedY][inputedX + i] = shipCounter;
		}
	}
	else
	{
		for (int i = 0; i < inputedSize; i++)
		{
			if (!board[inputedX + i][inputedX])
			{
				return false;
			}
		}

		for (int i = 0; i < inputedSize; i++)
		{
			board[inputedY + 1][inputedX] = shipCounter;
		}
	}

	shipCounter++;

	return true;
}

char* Board::IsShipPart(int &x, int &y)
{
	if (x < 0 || y < 0 || x > Row + 1 || y > Col + 1)
	{
		std::string error = "range error";
		return &error[0];
	}

	if (board[x][y] > 0) //if (board[x][y] && shipsOnBoard[board[x][y] - 1].getStatus = 'h')
	{
		board[x][y] = -1;
		std::string correct = "correct";
		return &correct[0];
	}
	else if (board[x][y] == -1)
	{
		std::string error = "already destroyed";
		return &error[0];
	}
	else
	{
		std::string error = "missed";
		return &error[0];
	}
}