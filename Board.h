#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include "Ship.h"


const int Col = 10;
const int Row = 10;

class Board
{
private:
	int board[Col][Row];
	std::vector<Ship> shipsOnBoard;
	int shipCounter = 1;
public:
	Board();
	~Board();
	bool CanPlace(Ship &);
	char* IsShipPart(int &x, int &y);
};

