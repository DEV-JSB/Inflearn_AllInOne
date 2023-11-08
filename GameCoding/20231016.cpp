#include "Player2.h"
#include <iostream>


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
};

void main()
{
	Knight knight;

}