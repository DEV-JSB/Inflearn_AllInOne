#pragma once

#include "Enum.h"

class Item
{
public:
	//Item();
	Item(ItemType itemType);
	virtual ~Item(); 

public:
	virtual void PrintInfo();
	ItemType GetItemType() { return _itemType; }
protected:
	int _itemId = 0;
	int _itemCount = 0;
	ItemRarity _rarity = IR_Normal;
	ItemType _itemType = IT_None;
};


class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();
	virtual void PrintInfo()override;

	void SetDamage(int damage) { _damage = damage; }
	int GetDamange() { return _damage; }
private:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();
	virtual void PrintInfo()override;

	void SetDefence(int defence) { _defence = defence; }
	int GetDefence() { return _defence; }
private:
	int _defence = 0;
};
