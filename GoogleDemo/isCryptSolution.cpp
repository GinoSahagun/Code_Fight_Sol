#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
using namespace std;
bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
	std::vector<uint64_t> numbers;

	int temp = 0;
	uint64_t temp1 = 0;
	for (int i = 0; i < solution.size(); i++)
	{
		for (int j = 0; j < crypt.size(); j++)
		{
			temp = crypt[j].find(solution[i][0]);
			while (temp != std::string::npos)
			{
				crypt[j].at(temp) = solution[i][1];
				temp = crypt[j].find(solution[i][0]);
			}
		}
	}

	for (int i = 0; i < crypt.size(); i++)
	{
		if (crypt[i].at(0) == '0' && crypt[i].size() == 1)
		{
			numbers.push_back(std::atoi(crypt[i].c_str()));
		}
		else if (crypt[i].at(0) == '0')
			return false;
		else {
			istringstream test(crypt[i]);
			if (!(test >> temp1))
				std::cout << "failed" << std::endl;
			else
				numbers.push_back(temp1);
		}
	}
	uint64_t sum = numbers[0] + numbers[1];

	if (sum == numbers[2])
		return true;

	return false;
}

int search(std::vector<std::vector<char>> arr, char c)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (c == arr[i][0])
		{
			return i;
		}
	}

	return -1;
}