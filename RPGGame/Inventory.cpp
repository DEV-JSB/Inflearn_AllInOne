#include "Inventory.h"

Inventory* Inventory::s_instance = nullptr;

Inventory::Inventory()
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		_items[i] = nullptr;
	}
}

Inventory::~Inventory()
{
}

bool Inventory::AddItem(Item* item)
{
	if (nullptr == item)
		return false;

	int emptySlot = FindEmptySlot();
	if (0 > emptySlot)
		return false;

	_items[emptySlot] = item;
	++_itemCount;
}

bool Inventory::RemoveItem(Item* item)
{
	if (nullptr == item)
		return false;

	int slot = FindItemSlot(item);
	if (0 > slot)
		return false;

	_items[slot] = nullptr;
	--_itemCount;
	//delete item;
	return true;
}

Item* Inventory::GetItemAtSlot(int slot)
{
	if (0 > slot || slot >= MAX_SLOT)
		return nullptr;
	return _items[slot];
}

void Inventory::Clear()
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (_items[i])
		{
			delete _items[i];
			_items[i] = nullptr;
		}
	}
}

Inventory* Inventory::GetInstance()
{
	if (nullptr == s_instance)
		s_instance = new Inventory();

	return s_instance;
}

int Inventory::FindEmptySlot()
{
	for (int i = 0; i < MAX_SLOT; ++i)
	{
		if (nullptr == _items[i])
			return i;
	}
	return -1;
}

int Inventory::FindItemSlot(Item* item)
{

	return 0;
}