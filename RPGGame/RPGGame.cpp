// RPGGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Item.h"
#include <iostream>
#include "Inventory.h"

using namespace std;
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
		bool addSuccess = Inventory::GetInstance()->AddItem(item);

		if (addSuccess)
		{
			cout << "Added Item to Inven" << endl;
		}
		else
		{
			cout << "Added Item to Inven" << endl;

		}

	}
	for (int i = 0; i < 20; ++i)
	{
		int randIndex = rand() % MAX_SLOT;
		Item* item = Inventory::GetInstance()->GetItemAtSlot(randIndex);
		if (item)
		{
			if (Inventory::GetInstance()->RemoveItem(item))
			{
				cout << "Remove Item" << endl;
			}
			else
			{

			}
		}
	}

}