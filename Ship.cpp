#include "ship.h"


Ship::Ship()
{
	while (1)
	{
		cout << "Size: ";
		cin >> size;
		if (size < 6 and size > 1)
			break;
	}

	while (1)
	{
		cout << "Rotation X or Y: ";
		cin >> rotation;
		if (rotation == 'X' or rotation == 'Y')
			break;
	}

	cout << "X and Y: " << endl;
	cin >> x;
	cin >> y;


}
