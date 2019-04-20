#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include "Ship.h"

class Board
{
private:
	std::vector<std::vector<int> > m_board;
	std::vector<Ship> m_shipsOnBoard;
	int m_shipCounter = 1;
	int m_row;
	int m_col;
public:
	Board(int, int);
	~Board();
	int GetRow();
	int GetCol();
	int GetFieldStatus(int x, int y);
	bool CanPlace(Ship &);
	char* IsShipPart(int &x, int &y);
};
