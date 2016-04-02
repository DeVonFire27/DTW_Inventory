#include "Store.h"
void Store::Load(const char * path)
{
	ifstream fin(path, ios_base::in);
	unsigned int runs, cost, weight;
	char type[16], name[16];
	fin >> runs;
	contents.reserve(runs);
	for(decltype(runs) x = 0; x < runs; x++)
	{
		fin >> type >> name >> cost >> weight;
		contents.append(Item(type, name, cost, weight));
	}

}

void Store::SortByType()
{
	DynArray<Item> temp(contents);
	contents.clear();
	Item thing;
	for(decltype(temp.size()) x = 0; x < temp.size() - 1; x++)
		for(decltype(temp.size()) y = x+1; y < temp.size(); y++)
		{
			if(_stricmp(temp[x].type, temp[y].type) > 0)
			{
				thing = temp[x];
				temp[x] = temp[y];
				temp[y] = thing;
			}
		}
	contents.reserve(temp.size());
	contents = temp;
}

void Store::SortByName()
{
	DynArray<Item> temp(contents);
	contents.clear();
	Item thing;
	for(decltype(temp.size()) x = 0; x < temp.size() - 1; x++)
		for(decltype(temp.size()) y = x+1; y < temp.size(); y++)
		{
			if(_stricmp(temp[x].name, temp[y].name) > 0 )
			{
				thing = temp[x];
				temp[x] = temp[y];
				temp[y] = thing;
			}
		}
	contents.reserve(temp.size());
	contents = temp;
}

void Store::SortByPrice()
{
	DynArray<Item> temp(contents);
	contents.clear();
	Item thing;
	for(decltype(temp.size()) x = 0; x < temp.size() - 1; x++)
		for(decltype(temp.size()) y = x+1; y < temp.size(); y++)
		{
			if(temp[x].cost > temp[y].cost)
			{
				thing = temp[x];
				temp[x] = temp[y];
				temp[y] = thing;
			}
		}
	contents.reserve(temp.size());
	contents = temp;
}

void Store::SortByWeight()
{
	DynArray<Item> temp(contents);
	contents.clear();
	Item thing;
	for(decltype(temp.size()) x = 0; x < temp.size() - 1; x++)
		for(decltype(temp.size()) y = x+1; y < temp.size(); y++)
		{
			if(temp[x].weight > temp[y].weight)
			{
				thing = temp[x];
				temp[x] = temp[y];
				temp[y] = thing;
			}
		}
	contents.reserve(temp.size());
	contents = temp;
}

void Store::Display()
{
	for(decltype(contents.size()) x = 0; x < contents.size(); x++)
	{
		cout << contents[x].type;
		for(int y = 0; y < (14 - (int)strlen(contents[x].type)); y++)
			cout << " ";
		cout << contents[x].name << '\t';
		cout << contents[x].cost << '\t';
		cout << contents[x].weight << '\n';
	}

}

bool Store::Search(const char * name)
{
	for(decltype(contents.size()) x = 0; x < contents.size(); x++)
	{
		if(_stricmp(contents[x].name, name) == 0)
			return true;
	}
	return false;
}

Item & Store::getItem(const char * name)
{
	decltype(contents.size()) x = 0;
	for(; x < contents.size(); x++)
	{
		if(_stricmp(contents[x].name, name) == 0)
			break;
	}
	return contents[x];
}
