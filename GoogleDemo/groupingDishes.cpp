#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
// Definition for singly-linked list:
template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	ListNode() : value(0), next(nullptr) {}
	T value;
	ListNode *next;

};
std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) {
	std::map<std::string, std::vector<string>> map;
	std::string dish;
	std::vector<std::vector<std::string>> group;
	for (int i = 0; i < dishes.size(); i++)
	{
		dish = dishes[i][0];
		for (int j = 1; j < dishes[i].size(); j++)
		{
			map[dishes[i][j]].push_back(dish);
		}

	}
	int col = 0;
	for (auto& kv : map) {
		std::cout << kv.first << endl;
		sort(kv.second.begin(), kv.second.end());
		if (kv.second.size() > 1)
		{
			std::vector<string> temp;
			group.push_back(temp);
			group[col].push_back(kv.first);
			for (int i = 0; i < kv.second.size(); i++)
			{
				group[col].push_back(kv.second[i]);
			}
			col++;
		}
		cout << endl;

	}

	return group;
}