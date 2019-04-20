#pragma once
class Ship
{
	int size;
	int life;
	char rotation;
	int x;
	int y;
	char status;

public:
	Ship(int);
	int getX() { return x; };
	int getY() { return y; };
	int getSize() { return size; }
	int getLife() { return life; }
	char getRot() { return rotation; }
	char getStatus() { return status; }
	void setStatus(char statusGiven) { status = statusGiven; }
	void reduceLife() { life--; };
};
