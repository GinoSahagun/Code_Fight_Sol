

#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
using namespace std;


int periodicSequence(int s0, int a, int b, int m) {
	std::vector<int> occurrence;
	int currentValue = s0;

	for (int i = 0; i < m; i++) {
		occurrence.push_back(-1);
	}
	occurrence[s0] = 0;
	for (int i = 1;; i++) {
		currentValue = (a * currentValue + b) % m;
		if (occurrence[currentValue] != -1) {
			return i - occurrence[currentValue];
		}
		occurrence[currentValue] = i;
	}

}




