#pragma once
class Ship
{
	int size;
	char rotation;
	int x;
	int y;
	char status;

public:
	Ship(int);
	int getX() { return x; };
	int getY() { return y; };
	int getSize() { return size; }
	char getRot() { return rotation; }
	char getStatus() { return status; }
	char setStatus(char statusGiven) { status = statusGiven; }
};
