#pragma once
#include "DynArray.h"
#include "Item.h"
#include <iostream>
#include <fstream>
using namespace std;
class Store
{

private:
	DynArray<Item> contents;

public:
	void Load(const char * path);
	void SortByType();
	void SortByName();
	void SortByPrice();
	void SortByWeight();
	void Display();
	Item & getItem(const char * name);
	bool Search(const char * name);

};

