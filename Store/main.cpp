#include "TransactionManager.h"
#include <ctime>
void FullDisplay(Store, Inventory);
void delay(const unsigned int milliSeconds);

int main(int argc, char ** argv)
{
	TransactionManager game;
	char option[16];
	while (true)
	{
		game.FullDisplay();
		cout << "Things to do:\n (Sort) the Store\n (Search) the Store\n (Buy) an Item\n (Sell) an Item\n (Undo)\n (Quit)";
		cout << "\nWhat would you like to do? ";
		while(true)
		{

			if(cin.get(option, 16, '\n'))
			{
				cin.ignore(INT_MAX, '\n');
				break;
			}

			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		//Input validation!!

		if(_stricmp(option, "sort") == 0 || _stricmp(option, "sort the store") == 0)
		{
			game.FullDisplay();
			//SortMenu();

			cout << "Sort options:\n";
			cout << " (By Type)\n (By Name)\n (By Price)\n (By Weight)\n";

			char sort[16];
			cout << "How would you like to sort: ";
			while (true)
			{
				if(cin.get(sort, 16, '\n'))
				{
					cin.ignore(INT_MAX, '\n'); 
					break;
				}
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}

			if(game.StoreStuff(sort))
				cout << "Item's have been properly sorted!";
			else
				cout << "Invalid sort type...";

			delay(1000);
		}
		else if(_stricmp(option, "search") == 0 || _stricmp(option, "search the store") == 0)
		{
			game.FullDisplay();
			char query[16];
			cout << "What do you want to search for?  ";
			while (true)
			{
				if(cin.get(query, 16, '\n'))
				{
					cin.ignore(INT_MAX, '\n'); 
					break;
				}
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			if(game.StoreStuff(query))
				cout << "We found a " << query << '\n';
			else
				cout << "We didn't find a " << query << '\n';
			delay(1000);
		}
		else if(_stricmp(option, "buy") == 0 || _stricmp(option, "buy an item") == 0)
		{
			game.FullDisplay();
			game.Buy();
			delay(1000);
		}
		else if(_stricmp(option, "sell") == 0 || _stricmp(option, "sell an item") == 0)
		{
			game.FullDisplay();
			game.Sell();
			delay(1000);
		}
		else if(_stricmp(option, "undo") == 0)
			game.Undo();
		else if(_stricmp(option, "quit") == 0)
			break;
		else
		{
			cout << "Invalid option...";
			delay(1000);
		}
	}
}

void delay(const unsigned int milliSeconds)
{
	unsigned int start = clock();
	while ((clock() - start) < milliSeconds) {}
}


