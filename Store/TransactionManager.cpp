#include "TransactionManager.h"
#include <iostream>
using namespace std;

TransactionManager::TransactionManager()
{
	refunds = 0;
	theStore.Load("items.shp");
}
void TransactionManager::Buy()
{
	char purchase[16];
	cout << "What item would you like to buy?   ";
	while (true)
	{
		if(cin.get(purchase, 16, '\n'))
		{
			cin.ignore(INT_MAX, '\n'); 
			break;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	if(theStore.Search(purchase))
	{
		Transaction temp;
		temp.theItem = theStore.getItem(purchase);
		temp.bought = true;
		if(temp.theItem.cost <= theInventory.getCoins() &&
			(theInventory.getWeight()+temp.theItem.weight) <= theInventory.getMWeight())
		{
			cout << "You purchase a " << temp.theItem.name << " for " << temp.theItem.cost << endl;
			theInventory.SetCoins(-(int)temp.theItem.cost);
			theInventory.SetWeight(temp.theItem.weight);
			theInventory.AddItem(temp.theItem);
			AddTransaction(temp);
		}
		else if(temp.theItem.cost > theInventory.getCoins())
			cout << "Not enough gold there! Ya can't afford that!" << endl;
		else
			cout << "That's a bit too much for you too carry there" << endl;
	}
	else
		cout << "We don't have that item...\n";
}

void TransactionManager::Sell()
{
	char sells[16];
	cout << "What item would you like to sell?   ";
	while (true)
	{
		if(cin.get(sells, 16, '\n'))
		{
			cin.ignore(INT_MAX, '\n'); 
			break;
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	if(theStore.Search(sells))
	{
		Transaction temp;
		temp.theItem = theStore.getItem(sells);
		temp.bought = false;
		if(theInventory.RemoveItem(temp.theItem))
		{
			cout << "You sold back a " << temp.theItem.name << " for " << temp.theItem.cost/2 << endl;
			theInventory.SetCoins(temp.theItem.cost/2);
			theInventory.SetWeight(-(int)temp.theItem.weight);
			AddTransaction(temp);
		}
	}
	else
		cout << "You don't have that item...\n";
}

void TransactionManager::Undo()
{
	if (refunds > 0)
	{
		SLLIter<Transaction> y(theHistory);
		y.begin();
		if(y.current().bought)
		{
			theInventory.SetCoins(y.current().theItem.cost);
			theInventory.SetWeight(-(int)y.current().theItem.weight);
			theInventory.RemoveItem(y.current().theItem);
		}
		else
		{
			theInventory.SetCoins(-((int)y.current().theItem.cost/2));
			theInventory.SetWeight(y.current().theItem.weight);
			theInventory.AddItem(y.current().theItem);
		}
		theHistory.remove(y);
		refunds--; 
	}
	else
		cout << "You can't undo anymore...";
}

void TransactionManager::AddTransaction(Transaction t)
{
	refunds++;
	if(refunds > 5)
	{
		SLLIter<Transaction> y(theHistory);
		y.begin();
		for(decltype(refunds) x = 1; x <= refunds; x++) { ++y; }
		theHistory.remove(++y);
		refunds--;
	}
	theHistory.addHead(t);
}

void TransactionManager::FullDisplay()
{
	system("cls");
	cout << "Welcome to the Store!!\n";
	cout << "===========================\n";
	cout << "Type          Name\tPrice\tWeight";
	cout << "\n===========================\n";
	theStore.Display();
	cout << "================================\n";
	theInventory.Display(); 
	cout << " {Undos:" << refunds << "}";
	cout << "\n================================\n";
}

bool TransactionManager::StoreStuff(char * job)
{
	if(_stricmp(job, "by type") == 0)
	{
		theStore.SortByType();
		return true;
	}
	else if(_stricmp(job, "by name") == 0)
	{
		theStore.SortByName();
		return true;
	}
	else if(_stricmp(job, "by price") == 0)
	{
		theStore.SortByPrice();
		return true;
	}
	else if(_stricmp(job, "by weight") == 0)
	{
		theStore.SortByWeight();
		return true;
	}
	else if(theStore.Search(job))
		return true;
	return false;
}