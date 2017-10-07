
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
bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) {

	std::map<std::string, std::string> map;
	std::set<string> set;
	std::set<string>::iterator it;
	int length = patterns.size() <= strings.size() ? patterns.size() : strings.size();
	for (int i = 0; i < length; i++)
	{
		it = set.find(strings[i]);
		if (it == set.end()) {
			map[patterns[i]] = strings[i];
			set.insert(strings[i]);
		}

	}

	for (int i = 0; i < length; i++)
	{
		if (strings[i] != map[patterns[i]]) {
			return false;
		}
	}
	return true;
}