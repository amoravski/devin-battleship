#include "Board.h"
class Player
{
public:
	std::string getName();
	int getTurn();
	int getNumber();
	int getShipsToPlace();
	int getShipsPlaced();
	void reduceShipsPlaced();
	void makeShip( Board & , int);
	bool attack(Board&, int, int);
	Player(int);
private:
	std::string name;
	bool first;
	int turn;
	int num;
	int shipsToPlace;
	int shipsPlaced;
};