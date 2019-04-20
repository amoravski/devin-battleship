class Player
{
public:
	std::string getName();
	int getTurn();
	int getNumber();
	int getShipsToPlace();
	int getShipsPlaced();
	void makeShip();
	Player(int);
private:
	std::string name;
	bool first;
	int turn;
	int num;
	int shipsToPlace;
	int shipsPlaced;
};