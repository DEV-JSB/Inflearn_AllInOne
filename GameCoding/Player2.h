#pragma once
class Player2
{

public:

	Player2(const Player2& other)
	{
		this->hp = other.hp;
		this->attack = other.attack;
		this->defense = other.defense;
	}
	void Attack();
	void Die();
	void HealMe(int value);
public:
	int hp;
	int attack;
	int defense;

};

