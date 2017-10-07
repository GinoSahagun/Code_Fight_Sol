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

bool containsCloseNums(std::vector<int> nums, int k) {
	std::map<int, int> map;
	std::map<int, int>::iterator it;
	int diff;
	for (int i = 0; i < nums.size(); i++)
	{
		it = map.find(nums[i]);
		if (it == map.end())
		{
			map[nums[i]] = i;
		}
		else
		{
			diff = map[nums[i]] <= i ? i - map[nums[i]] : map[nums[i]] - i;
			if (diff <= k)
				return true;
			map[nums[i]] = i;
		}
	}

	return false;

}