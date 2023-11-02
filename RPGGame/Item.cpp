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

Weapon::Weapon()
{
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

Armor::Armor()
{
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
