#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

const int N = 10;
const int M = 10;

class Board
{
private:
	int board1[N][M];
	int board2[N][M];
	int shipCounter = 1;
public:
	Board();
	~Board();
	bool CanPlace(Ship &, int turn);
	std::exception* IsShipPart(int &x, int &y, int turn);
};

