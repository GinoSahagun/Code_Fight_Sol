

#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
using namespace std;




void removeItems(std::stack<int> &stuff) {
	while (!stuff.empty())
		stuff.pop();
}
int zigzag(std::vector<int> a) {

	if (a.size() == 0)
		return 1;

	std::vector<bool> map(a.size(), false);
	std::stack<int> real;

	for (int i = 0; i < map.size(); i++)
		cout << a[i] << " ";

	cout << endl;

	for (int i = 0; i < a.size(); i++)
	{
		if (i != 0 && i != a.size() - 1 && a[i] > a[i - 1] && a[i] > a[i + 1])
			map[i] = true;
		else if ((i == 0) && a[i] > a[i + 1])
			map[i] = true;
		else if ((i == 0) && a[i] < a[i + 1])
			map[i] = true;
		else if (i != 0 && i != a.size() - 1 && a[i] < a[i - 1] && a[i] < a[i + 1])
			map[i] = true;
		else if (i == a.size() - 1 && a[i] < a[i - 1])
			map[i] = true;
		else if (i == a.size() - 1 && a[i] > a[i - 1])
			map[i] = true;
		else {
			map[i] = false;
		}
	}
	int length = 1;
	int cur = 0;
	for (int i = 0; i < map.size(); i++)
		cout << map[i] << " ";
	cout << endl;
	for (int i = 0; i < map.size(); i++)
	{
		if (map[i] == true) {
			if (i != 0)
			{
				if (real.empty()) {
					real.push(a[i - 1]);
					real.push(a[i]);
					real.push(a[i + 1]);
				}
				else if (map[i - 1] == true)
				{
					if (i < map.size() - 1)
						real.push(a[i + 1]);
				}
			}
			else if (i == 0)
			{
				if (real.empty()) {

					real.push(a[i]);
					real.push(a[i + 1]);
				}
				else if (map[i - 1] == true)
				{
					real.push(a[i + 1]);
				}
			}
			else if (i == a.size() - 1)
			{
				if (real.empty()) {
					real.push(a[i - 1]);
					real.push(a[i]);
				}
				else if (map[i - 1] == true)
				{
					real.push(a[i]);
				}
			}
			else
			{
				length = real.size();
				if (length > cur)
					cur = length;
				removeItems(real);
			}



		}
		else {
			length = real.size();
			if (length > cur)
				cur = length;
			removeItems(real);
		}


	}

	length = real.size();
	if (length > cur)
		cur = length;
	removeItems(real);

	cout << cur << endl;
	cout << length << endl;

	return cur;
}





