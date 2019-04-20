#include<iostream>
#include<string>
#include "player.h"
#include "Ship.h"
#include "Board.h"

Player::Player(int number)
{
    std::cout << "Making player number " << number << "...\n";
    std::cout << "Enter name: ";
    std::cin >> name;
    num = number;
	turn = number;
	shipsToPlace = 10;
	shipsPlaced = 0;
}

std::string Player::getName() 
{
    return name;
}

int Player::getTurn() 
{
    return turn;
}

int Player::getNumber() 
{
    return num;
}

int Player::getShipsToPlace()
{
	return shipsToPlace;
}

int Player::getShipsPlaced()
{
	return shipsPlaced;
}

void Player::makeShip(Board& b, int size)
{
	Ship ship(size);
	// Send to board

	b.CanPlace(ship);

	shipsToPlace--;
	shipsPlaced++;
}

bool Player::attack(Board& b, int x, int y)
{
	std::string result = b.IsShipPart(x, y);
	std::cout << result;
	return true;
}
