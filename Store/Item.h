#pragma once
#include <iostream>
using namespace std;
struct Item
{	
	char type[16];
	char name[16];
	unsigned int cost;
	unsigned int weight;

	Item(const char * t, const char * n, unsigned int c, unsigned int w)
	{
		strcpy_s(type, 16, t);
		strcpy_s(name, 16, n);
		cost = c;
		weight = w;
	}

	Item() {}

};
