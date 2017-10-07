
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
//Brute Force Next Larger
//std::vector<int> nextLarger(std::vector<int> a) {
//
//	std::vector<int> boo;
//	int nextG;
//	for (int i = 0; i < a.size(); i++)
//	{
//		nextG = -1;
//		for (int j = i; j < a.size(); j++)
//		{
//			if (a[i] < a[j])
//			{
//				nextG = a[j];
//				boo.push_back(nextG);
//				break;
//			}
//		}
//		if (nextG == -1)
//			boo.push_back(nextG);
//	}
//
//	return boo;
//
//}

//Optimized Version
std::vector<int> nextLarger(std::vector<int> a) {

	std::vector<int> r(a.size(), -1);
	std::stack<int> s;
	for (int i = 0; i < a.size(); ++i)
	{
		while (!s.empty() && a[s.top()] < a[i])
		{
			r[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	return r;

}