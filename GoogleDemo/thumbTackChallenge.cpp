

#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;
void displayMap(std::map<string, std::vector<string>> map)
{
	/*std::map<string, vector<string>>::const_iterator MapIterator;
	for (MapIterator = map.begin(); MapIterator != map.end(); MapIterator++)
	{
	cout << "Key: " << MapIterator->first << endl << "Values:" << endl;
	vector<string>::const_iterator list_iter;
	for ( list_iter = MapIterator->second.begin(); list_iter != MapIterator->second.end(); list_iter++)
	cout << " " << *list_iter << endl;
	}*/
	for (const auto& kv : map) {
		std::cout << kv.first << endl;
		for (int i = 0; i < kv.second.size(); i++)
		{
			cout << kv.second[i] << ",";
		}
		cout << endl;
	}
}


void addMap(std::vector<std::vector<std::vector<std::string>>> &grid, std::map<string, std::vector<string>> map)
{

	int i = 0;
	for (auto& kv : map) {
		std::vector<string> names(kv.second);
		std::vector<string> preference = { kv.first };
		std::vector<std::vector<string>> mapping = { preference, names };
		grid[i] = mapping;
		i++;
		cout << endl;
	}
}

std::vector<std::vector<std::vector<std::string>>> proCategorization(std::vector<std::string> pros, std::vector<std::vector<std::string>> preferences) {

	std::map<string, std::vector<string>> map;

	for (int i = 0; i < preferences.size(); i++)
	{
		for (int j = 0; j < preferences[i].size(); j++)
		{
			map[preferences[i][j]].push_back(pros[i]);
		}
	}
	std::vector<std::vector<std::vector<std::string>>> proCat(map.size());
	cout << proCat.size();


	displayMap(map);
	addMap(proCat, map);

	return proCat;
}
