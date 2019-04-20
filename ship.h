#include <iostream>
using namespace std;

class Ship
{
	int size;
	char rotation;
	int x;
	int y;

public:
	Ship();
	int getX() { return x; };
	int getY() { return y; };
	int getSSize() { return size; }
	char getRot() { return rotation; }
};
