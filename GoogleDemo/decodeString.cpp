

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


string mult(pair<string, int>& p) {
	string r;
	for (; p.second--;) {
		r += p.first;
	}
	return r;
}

string decodeString(string s) {
	vector<pair<string, int>> v;
	v.push_back({ "",1 });
	int n = 0;
	for (char c : s) {
		if (c == '[') {
			v.push_back({ "",n });
			n = 0;
		}
		else if (c == ']') {
			auto q = mult(v.back());
			v.pop_back();
			v.back().first += q;
		}
		else if (isdigit(c)) {
			n = 10 * n + c - '0';
		}
		else {
			v.back().first += c;
		}
	}
	return v[0].first;
}