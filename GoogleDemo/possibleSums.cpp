


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
int possibleSums(std::vector<int> coins, std::vector<int> quantity) {

	std::vector<int> solutions;
	std:vector<int> values(quantity.size() - 1, 0);
	values.push_back(1);

	while (true)
	{
		int total = 0;

		for (int i = 0; i < coins.size(); ++i)
			total += coins[i] * values[i];

		solutions.push_back(total);

		int i = values.size();
		do
		{
			if (i != values.size())
				values[i] = 0;

			--i;

			if (i < 0)
				break;

		} while (++values[i] > quantity[i]);

		if (values[0] == 0 && i < 0)
			break;

	}

	std::sort(solutions.begin(), solutions.end());
	solutions.erase(std::unique(solutions.begin(), solutions.end()), solutions.end());
	return solutions.size();
}