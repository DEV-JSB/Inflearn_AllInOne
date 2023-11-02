#include "Item.h"

#include<iostream>	
using namespace std;
Item::Item()
{
	int randValue = rand() % 100;
	if (randValue < 50)
	{
		_rarity = IR_Normal;
	}
	else if (randValue < 80)
	{
		_rarity = IR_Rare;
	}
	else
	{
		_rarity = IR_Unique;
	}
}

Item::~Item()
{
}

void Item::PrintInfo()
{
	switch (_rarity)
	{
	case IR_Normal:
		cout << "일반";
		break;
	case IR_Rare:
		cout << "레어";
		break;
	case IR_Unique:
		cout << "유니크";
		break;
	default:
		break;
	}
	cout << endl;

}

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

void Weapon::PrintInfo()
{
	Item::PrintInfo();

	cout << "아이템 타입 : 무기" << endl;
	cout << "데미지 : " << _damage <<endl;

}

Armor::Armor()
{
}

Armor::~Armor()
{
}

void Armor::PrintInfo()
{
	Item::PrintInfo();

	cout << "아이템 타입 : 방어구" << endl;
	cout << "방어력 : " << _defence << endl;

}
