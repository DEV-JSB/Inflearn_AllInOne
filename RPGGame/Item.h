#pragma once


enum ItemRarity
{
	IR_Normal,
	IR_Rare,
	IR_Unique
};

class Item
{


public:
	Item();
	virtual ~Item();

	virtual void PrintInfo();

protected:
	int _itemId = 0;
	int _itemCount = 0;
	ItemRarity _rarity;
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
