#include "Board.h"

Board::Board(int row, int col)
{
	m_row = row;
	m_col = col;
	Ship p;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			m_board[i][k] = p;
		}
	}
}

Board::~Board()
{
}

int Board::GetCol()
{
	return m_col;
}

int Board::GetRow()
{
	return m_row;
}

int Board::GetFieldStatus(int x, int y)
{
	return m_board[x][y];
}

bool Board::CanPlace(Ship &inputed, int turn)
{	
	int inputedX = inputed.GetX();
	int inputedY = inputed.GetY();
	char inputedRot = inputed.GetRot();
	int inputedSize = inputed.GetSize();

	///If the cordinates are in the range of the board

	if (inputedX == 0 || inputedY == 0
		|| (inputedX + inputedSize) > m_row - 1 || (inputedY + inputedSize) > m_col - 1)
	{
		return false;
	}

	///If the rotate is right (X), check if there is no other ship, pull it
	///else the rotate is down (Y) and -||-

	if (inputedRot == 'X')
	{
		for (int i = 0; i < inputedSize; i++)
		{
			if (!m_board[inputedY][inputedX + i])
			{
				return false;
			}
		}
		m_shipsOnBoard.push_back(inputed);
		for (int i = 0; i < inputedSize; i++)
		{
			m_board[inputedY][inputedX + i] = m_shipCounter;
		}
	}
	else
	{
		for (int i = 0; i < inputedSize; i++)
		{
			if (!m_board[inputedX + i][inputedX])
			{
				return false;
			}
		}

		for (int i = 0; i < inputedSize; i++)
		{
			m_board[inputedY + 1][inputedX] = m_shipCounter;
		}
	}

	m_shipCounter++;

	return true;
}

char* Board::IsShipPart(int &x, int &y)
{
	///If the cordinates are in the range of the board

	if (x < 0 || y < 0 || x > m_row + 1 || y > m_col + 1)
	{
		std::string error = "range error";
		return &error[0];
	}

	///check if there is a ship either there is a destroyed one or there is nothing

	if (m_board[x][y] > 0)
	{
		m_board[x][y] = -1;
		std::string correct = "correct";
		return &correct[0];
	}
	else if (m_board[x][y] == -1)
	{
		std::string error = "already destroyed";
		return &error[0];
	}
	else
	{
		m_board[x][y] = -2;
		std::string error = "missed";
		return &error[0];
	}
}