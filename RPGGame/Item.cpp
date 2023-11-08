#include "Item.h"

#include<iostream>	
using namespace std;

Item::Item(ItemType itemType)
	:_itemType(itemType)
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
		cout << "�Ϲ�";
		break;
	case IR_Rare:
		cout << "����";
		break;
	case IR_Unique:
		cout << "����ũ";
		break;
	default:
		break;
	}
	cout << endl;

}

Weapon::Weapon():Item(ItemType::IT_Weapon)
{

	switch (_rarity)
	{
	case IR_Normal:
		_damage = 1 + rand() % 5;
		break;

	case IR_Rare:
		_damage = 10 + rand() % 5;
		break;

	case IR_Unique:
		_damage = 20 + rand() % 5;
		break;

	}
}

Weapon::~Weapon()
{
}

void Weapon::PrintInfo()
{
	Item::PrintInfo();

	cout << "������ Ÿ�� : ����" << endl;
	cout << "������ : " << _damage <<endl;

}

Armor::Armor():Item(ItemType::IT_Armor)
{
	switch (_rarity)
	{
	case IR_Normal:
		_defence = 1 + rand() % 5;
		break;

	case IR_Rare:
		_defence = 2 + rand() % 5;
		break;

	case IR_Unique:
		_defence = 3 + rand() % 5;
		break;

	}
}

Armor::~Armor()
{
}

void Armor::PrintInfo()
{
	Item::PrintInfo();

	cout << "������ Ÿ�� : ��" << endl;
	cout << "���� : " << _defence << endl;

}
