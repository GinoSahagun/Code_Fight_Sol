


#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include "Aho_CoraSick.h"

using namespace std;


int kthLargestElement(std::vector<int> nums, int k) {

	std::sort(nums.begin(), nums.end());
	std::reverse(nums.begin(), nums.end());
	return nums[k];
}