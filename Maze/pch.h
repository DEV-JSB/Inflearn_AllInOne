#pragma once

#include"Types.h"
#include <iostream>
#include <Windows.h>
using namespace std;


struct Pos
{
	Pos(){}
	Pos(int32 y, int32 x): y(y),x(x){}


	bool operator==(const Pos& other)
	{
		return y == other.y && x == other.x;
	}

	bool operator!= (const Pos & other)
	{
		return !(*this == other);
	}

	Pos operator+(const Pos& other)
	{
		return Pos{ y + other.y,x + other.x };
	}

	Pos& operator+=(const Pos& other)
	{
		y += other.y;
		x += other.x;
		return *this;
	}
	int32 y = 0;
	int32 x = 0;
};

enum Dir
{
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT =3,
	DIR_COUNT =4
};