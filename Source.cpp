#include<iostream>
#include "player.h"
#include "Ship.h"
#include "Board.h"

void placeShips(Player&, Board&, int*);
void enterShips(int[]);
std::ostream& operator<<(std::ostream&, Board&);

int main()
{
	int shipCount[4];

	enterShips(shipCount);

	Player playerOne(1);
	Board boardOne(10,10);
	
	Player playerTwo(2);
	Board boardTwo(10,10);

	placeShips(playerOne, boardOne, shipCount);
	placeShips(playerTwo, boardTwo, shipCount);
	system("pause");

	int turnCounter = 1;
	while (playerOne.getShipsPlaced() != 0 && playerTwo.getShipsPlaced() != 0) {
		int xcoord = 0, ycoord = 0;
		if (turnCounter % 2 == 0) {
			std::cout << boardOne;
			std::cout << "Player " << playerTwo.getName() <<"'s turn\nEnter coordinates:\nX:";
			std::cin >> xcoord;
			std::cout << "Y:";
			std::cin >> ycoord;
			if (playerTwo.attack(boardOne, xcoord, ycoord)) {
				turnCounter--;
			}
			system("pause");
			system("cls");
		}
		else
		{
			std::cout << boardTwo;
			std::cout << "Player " << playerOne.getName() << "'s turn\nEnter coordinates:\nX:";
			std::cin >> xcoord;
			std::cout << "Y:";
			std::cin >> ycoord;
			if (playerOne.attack(boardTwo, xcoord, ycoord)) {
				turnCounter--;
			}
			system("pause");
			system("cls");
		}
		turnCounter++;
	}
	system("cls");
	if (playerOne.getShipsPlaced() == 0) {
		std::cout << boardTwo;
		std::cout << "Player " << playerTwo.getName() << " has won!!! Thanks for playing";
		return 0;
	}
	else
	{
		std::cout << boardOne;
		std::cout << "Player " << playerOne.getName() << " has won!!! Thanks for playing";
		return 0;
	}


	return 0;
}

void placeShips(Player& player, Board& board, int shipCount[]) {
	system("cls");
	std::cout << "Enter ships for " << player.getName() << " :" << std::endl;
	for (int i = 0; i < 4;i++)
	{
		for (int j = 0; j < shipCount[i]; j++)
		{
			
			std::cout << "Information for ship number " << player.getShipsPlaced() + 1 << std::endl;
			player.makeShip(board, i+2);
			board.PrintAllShips();
		}
	}

	system("pause");
	system("cls");
	
}

void enterShips(int shipCount[])
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Enter ships with size " << i + 2 << ": ";
		std::cin >> shipCount[i];
	}
	system("pause");
	system("cls");
}

std::ostream& operator<<(std::ostream& output, Board& received){
	///TODO : legend info once in the begining
	output << "  |";

	for (int i = 0; i < received.GetRow(); i++)
	{
		output << i + 1 << " ";
	}
	output << std::endl;
	output << "--+";

	for (int i = 0; i < 2 * received.GetRow() - 2; i++)
	{
		output << "-";
	}

	output << std::endl;

	for (int i = 0; i < received.GetRow(); i++)
	{
		if (i < 9) {
			output << i + 1 << " |";
		}
		else
		{
			output << i + 1 << "|";
		}
		for (int k = 0; k < received.GetCol(); k++)
		{
			if (received.GetFieldStatus(i, k) >= 0)
			{
				output << "_ ";
			}
			else if (received.GetFieldStatus(i, k) == -1)
			{
				output << "d ";
			}
			else
			{
				output << "m ";
			}
		}
		output << std::endl;
	}
	return output;
}