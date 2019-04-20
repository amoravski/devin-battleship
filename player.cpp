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

Player::getName() 
{
    return name;
}

Player::getTurn() 
{
    return turn;
}

Player::getNumber() 
{
    return num;
}
