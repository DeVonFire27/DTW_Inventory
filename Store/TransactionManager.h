#pragma once
#include "Store.h"
#include "SLList.h"
#include "Inventory.h"
class TransactionManager
{
	struct Transaction
	{
		Item theItem;
		bool bought;
	};

	Store theStore;
	Inventory theInventory;
	SLList<Transaction> theHistory;
	unsigned int refunds;
	void AddTransaction(Transaction t);
public:
	TransactionManager();
	void Buy();
	void Sell();
	void Undo();
	void FullDisplay();
	bool StoreStuff(char * job);
	

};

