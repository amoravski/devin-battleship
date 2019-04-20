#include<iostream>
#include "player.h"
#include "Ship.h"
#include "Board.h"

void placeShips(Player&, Board&);
void enterShips(int[]);

int main()
{
	int shipCount[4];

	enterShips(shipCount&);

	Player playerOne(1);
	Board boardOne;
	
	Player playerTwo(2);
	Board boardTwo;

	placeShips(playerOne, boardOne);
	placeShips(playerTwo, boardTwo);

	int turnCounter = 0;
	while (playerOne.getShipsPlaced() != 0 && playerTwo.getShipsPlaced() != 0) {
		if (turnCounter % 2 == 0) {
			
		}
		else
		{
			// Player one attack
		}
		turnCounter++;
	}

	if (playerOne.getShipsPlaced() == 0) {
		std::cout << "Player " << playerTwo.getName() << " has won!!! Thanks for playing";
		return 0;
	}
	else
	{
		std::cout << "Player " << playerOne.getName() << " has won!!! Thanks for playing";
		return 0;
	}


	return 0;
}

void placeShips(Player& player, Board& board) {
	std::cout << "Enter ships for " << player.getName() << " :" << std::endl;
	while (player.getShipsToPlace() > 0)
	{
		std::cout << "Information for ship number " << player.getShipsPlaced() + 1 << std::endl;
		player.makeShip(board, );
		//print-board one with hidden ships
	}
}

void enterShips(int shipCount[])
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Enter ships with size " << i + 2 << ": ";
		std::cin >> shipCount[i];
	}
}