

#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
#include <map>
using namespace std;

class point {
public:
	point() {
		
	}
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	friend ostream& operator<<(ostream &os, const point& p)
	{
		os << p.x << "," << p.y;
		return os;
	}
private:
	int x, y;


};



bool sudoku2(std::vector<std::vector<char>> grid) {


	std::set<char> map1;
	std::set<char> map2;
	std::set<char> map3;
	std::set<char> map4;

	//mymap.insert ( std::pair<char,int>('a',100) );
	for (int i = 0; i < grid.size(); i++) {
		if (i % 3 == 0 && i != 0)
		{
			map2.clear();
			map3.clear();
			map4.clear();
		}
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] != '.') {
				if (map1.find(grid[j][i]) != map1.end()) {
					return false;
				}
				map1.insert(grid[i][j]);

				if (j <= 2)
				{
					if (map2.find(grid[i][j]) != map2.end())
					{
						return false;
					}
					map2.insert(grid[i][j]);
				}

				if (2 < j && j <= 5)
				{
					if (map3.find(grid[i][j]) != map3.end())
					{
						return false;
					}
					map3.insert(grid[i][j]);
				}
				if (5 < j && j <= 8)
				{
					if (map4.find(grid[i][j]) != map4.end())
					{
						return false;
					}
					map4.insert(grid[i][j]);
				}

			}




		}
		map1.clear();

	}


	return true;

}

int main()
{
	point p(2, 1);
	cout << p;
	std::vector<std::vector<char>> grid = { { '.', '8', '7', '6', '5', '4', '3', '2', '1' },
	{'2', '.', '6', '.', '.', '.', '.', '.', '.'},
	{'3', '.', '.', '.', '.', '.', '.', '.', '.'},
	{'4', '.', '1', '.', '.', '.', '.', '.', '.'},
	{'5', '6', '7', '.', '.', '.', '.', '.', '9'},
	{'6', '.', '.', '.', '.', '.', '8', '1', '.'},
	{'7', '3', '.', '.', '.', '.', '.', '.', '6'},
	{'8', '.', '.', '.', '.', '7', '.', '.', '.'},
	{'9', '.', '.', '5', '.', '.', '.', '7', '.'}};

	//std::vector<std::vector<std::string>> str = 
	//{ ".", "8", "7", "6", "5", "4", "3", "2", "1" },
	//{ "2", ".", ".", ".", ".", ".", ".", ".", "." },
	//{ "3", ".", ".", ".", ".", ".", ".", ".", "." },
	//{ "4", ".", ".", ".", ".", ".", ".", ".", "." },
	//{ "5", ".", ".", ".", ".", ".", ".", ".", "." },
	//{ "6", ".", ".", ".", ".", ".", ".", ".", "." },
	//{ "7", ".", ".", ".", ".", ".", ".", ".", "." },
	//{ "8", ".", ".", ".", ".", ".", ".", ".", "." },
	//{ "9", ".", ".", ".", ".", ".", ".", ".", "." } };

	cout << boolalpha << sudoku2(grid) << endl;

	return 0;
}

