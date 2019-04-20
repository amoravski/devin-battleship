#include<iostream>
#include<string>
#include "player.h"

Player::Player(int number)
{
    std::cout << "Making player number:" << number << "...\n";
    std::cout << "Enter name: ";
    std::cin >> name;
    num = number;
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
