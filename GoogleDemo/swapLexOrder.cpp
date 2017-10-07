

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
int root(int u, vector<int>& lab) {
	if (lab[u] < 0) return u;
	return lab[u] = root(lab[u], lab);
}

void unite(int u, int v, vector<int>& lab) {
	if (lab[u] > lab[v]) swap(u, v);
	lab[u] += lab[v];
	lab[v] = u;
}
std::string swapLexOrder(std::string str, std::vector<std::vector<int> > pairs) {
	vector<int> lab(str.size());
	for (int i = 0; i < str.size(); i++)
		lab[i] = -1;

	for (int i = 0; i < pairs.size(); i++) {
		int u = pairs[i][0] - 1, v = pairs[i][1] - 1;
		u = root(u, lab), v = root(v, lab);
		if (u != v) unite(u, v, lab);
	}

	multiset<char> *S = new multiset<char>[str.size()];
	for (int i = 0; i < str.size(); i++) {
		int u = root(i, lab);

		S[u].insert(str[i]);
	}

	for (int i = 0; i < str.size(); i++) {
		int u = root(i, lab);

		str[i] = *S[u].rbegin();
		S[u].erase(--S[u].end());
	}

	return str;
}