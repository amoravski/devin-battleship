#include<iostream>
#include<string>
#include "player.h"
#include "Ship.h"

Player::Player(int number)
{
    std::cout << "Making player number:" << number << "...\n";
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

void Player::makeShip()
{
	Ship ship;
	// Send to board
	shipsToPlace--;
	shipsPlaced++;
}
