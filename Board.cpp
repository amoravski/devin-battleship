#include "Board.h"

Board::Board(int row, int col)
{
	m_board.resize(col);
	m_row = row;
	m_col = col;
	for (int i = 0; i < row; i++)
	{
		for (int k = 0; k < col; k++)
		{
			m_board[i].push_back(0);
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

void Board::GetShip(int x, int y)
{
	//for (int i = 0;i < m_shipsOnBoard.size();i++) std::cout << m_shipsOnBoard[i].getLife();
	//return &m_shipsOnBoard[m_board[x][y] -1];
	m_shipsOnBoard[m_board[x][y] - 1].reduceLife();
	std::cout << m_shipsOnBoard[m_board[x][y] - 1].getLife();
}

bool Board::CanPlace(Ship inputed)
{	
	int inputedX = inputed.getX();
	int inputedY = inputed.	getY();
	char inputedRot = inputed.getRot();
	int inputedSize = inputed.getSize();

	///If the cordinates are in the range of the board

	if (inputedX < 0 || inputedY < 0
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
			if (m_board[inputedY][inputedX + i] > 0)
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
			if (m_board[inputedY + i][inputedX] > 0)
			{
				return false;
			}
		}
		m_shipsOnBoard.push_back(inputed);
		for (int i = 0; i < inputedSize; i++)
		{
			m_board[inputedY + i][inputedX] = m_shipCounter;
		}
	}

	m_shipCounter++;

	return true;
}

std::string Board::IsShipPart(int &p, int &x, int &y)
{
	///If the cordinates are in the range of the board

	x--;
	y--;

	if (x < 0 || y < 0 || x > m_row || y > m_col)
	{
		std::string error = "Out of range\n";
		return error;
	}

	///check if there is a ship either there is a destroyed one or there is nothing

	if (m_board[y][x] > 0)
	{
		m_shipsOnBoard[m_board[y][x] - 1].reduceLife();
		if (m_shipsOnBoard[m_board[y][x] - 1].getLife() == 0)
		{
			p--;
			std::cout << "One ship has been destroyed!\n";
		}

		m_board[y][x] = -1;
		std::string correct = "Hit!\n";
		return correct;
	}
	else if (m_board[y][x] == -1)
	{
		std::string error = "Already destroyed!\n";
		return error;
	}
	else
	{
		m_board[y][x] = -2;
		std::string error = "Missed\n";
		return error;
	}
}

void Board::PrintAllShips()
{
	std::cout << "  |";

	for (int i = 0; i < m_row; i++)
	{
		std::cout << i + 1 << " ";
	}
	std::cout << std::endl;
	std::cout << "--+";

	for (int i = 0; i < 2 * m_row - 2; i++)
	{
		std::cout << "-";
	}

	std::cout << std::endl;

	for (int i = 0; i < m_row; i++)
	{
		if (i < 9) {
			std::cout << i + 1 << " |";
		}
		else
		{
			std::cout << i + 1 << "|";
		}
		for (int k = 0; k < m_col; k++)
		{
			if (GetFieldStatus(i, k) == 0)
			{
				std::cout << "_ ";
			}
			else
			{
				std::cout << "h ";
			}
		}
		std::cout << std::endl;
	}
}