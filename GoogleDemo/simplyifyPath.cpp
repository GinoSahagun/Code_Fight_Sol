

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
std::string simplifyPath(std::string path) {
	std::string relative = "";
	std::string temp = "";
	std::vector<string> q;
	int start = 0;
	for (int i = 0; i < path.size(); i++)
	{
		if (path.at(i) == '/')
		{
			if (temp == ".." && !q.empty())
				q.pop_back();
			else if (temp != "" && temp != "/" && temp != "." && temp != "..")
				q.push_back(temp);

			temp = "";
		}
		if (path.at(i) != '/')
			temp += path.at(i);

	}
	if (temp == "..")
		q.pop_back();
	else if (temp != "/" && temp != "")
		q.push_back(temp);


	for (int i = 0; i < q.size(); i++)
	{
		relative += '/';
		relative += q[i];

	}

	return relative != "" ? relative : "";

}