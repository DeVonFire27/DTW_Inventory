#pragma once
#include "Item.h"
#include "SLList.h"
class Inventory
{
	SLList <Item> items;
	unsigned int coins, weight, maxWeight;
public:
	void AddItem(Item x);
	bool RemoveItem(Item x);
	void Display();
	Inventory();
	unsigned int getCoins() const { return coins; }
	unsigned int getWeight() const { return weight; }
	unsigned int getMWeight() const { return maxWeight; }

	void SetCoins(int x) { coins+=x; }
	void SetWeight(int x) { weight+=x; }


};

