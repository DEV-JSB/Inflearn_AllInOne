// RPGGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Item.h"
#include <iostream>

// 몬스터 잡을시
Item* DropItem()
{
	if(rand()%2 == 0)
	{
		Weapon* weapon = new Weapon();
		return weapon;
	}
	else
	{
		Armor* armor = new Armor();
		return armor;
	}
}
int main()
{
	srand((unsigned)time(0));

	for (int i = 0; i < 100; ++i)
	{
		Item* item = DropItem();
		item->PrintInfo();
	}

}