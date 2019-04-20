#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

bool Board::CanPlace(Ship &inputed, int turn)
{	
	int inputedX = inputed.GetX();
	int inputedY = inputed.GetY();
	char inputedRot = inputed.GetRot();
	int inputedSize = inputed.GetSize();

	if (inputedX == 0 || inputedY == 0
		|| (inputedX + inputedSize) > N - 1 || (inputedY + inputedSize) > M - 1)
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

char* Board::IsShipPart(int &x, int &y, int turn)
{
	if (x < 0 || y < 0 || x > N + 1 || y > M + 1)
	{
		std::string error = "range error";
		return &error[0];
	}

	if(board[])
}