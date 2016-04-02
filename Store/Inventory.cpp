#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory()
{
	coins = 5000;
	weight = 0;
	maxWeight = 50;
}

void Inventory::AddItem(Item x)
{
	items.addHead(x);
}

bool Inventory::RemoveItem(Item x)
{
	SLLIter<Item> y(items);
	for(y.begin(); !y.end(); ++y)
	{
		if(_stricmp(y.current().name, x.name) == 0)
		{
			items.remove(y);
			return true;
		}
	}
	cout << "You don't have that item..." << endl;
	return false;

}

void Inventory::Display()
{
	cout << "Player's Inventory\t(Gold: " << coins << " )\t [Weight:" 
		<< weight << "/" << maxWeight << "]\n";
	SLLIter<Item> y(items);
	for(y.begin(); !y.end(); ++y)
	{
		cout << y.current().type;
		for(int x = 0; x < (14 - (int)strlen(y.current().type)) ; x++)
			cout << " ";
		cout << y.current().name << '\t';
		cout << y.current().cost << '\t';
		cout << y.current().weight << '\n';

	}

}


