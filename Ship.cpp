#include "Ship.h"
#include<iostream>
using namespace std;

Ship::Ship(int sizeGiven)
{
	status = 'h';
	cout << "Placing a ship with size: " << sizeGiven << endl;
	size = sizeGiven;
	life = size;
	while (1)
	{
		cout << "Rotation X or Y: ";				//Up-Down or Left-Right direction
		cin >> rotation;
		if (rotation == 'X' or rotation == 'Y')
			break;
	}

	cout << "X and Y: " << endl;					//Starting Coardinates
	cin >> x;
	cin >> y;
	x--;
	y--;
}
