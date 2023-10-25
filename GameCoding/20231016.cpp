#include "Player2.h"
#include <iostream>


class Inventory
{
public:
	Inventory()
	{
		std::cout << "Inventory()";

	}
	~Inventory()
	{
		std::cout << "~Inventory()";

	}
};
class Player
{
public:
	Player()
	{
		std::cout << "Player()";
	}
	virtual ~Player()
	{
		std::cout << "~Player()";
	}
};

class Knight : Player
{
public:
	Knight()
	{
		std::cout << "Knight()";
	}
	virtual ~Knight()
	{
		std::cout << "~Knight()";
	}
public:
	int a = 0;
	Inventory inven;
};

void main()
{
	Knight knight;

}