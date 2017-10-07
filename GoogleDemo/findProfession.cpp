

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

//Definition for binary tree:
template<typename T>
struct Tree {
	Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
	T value;
	Tree *left;
	Tree *right;

	void add(int val, Tree *&tree)
	{
		if (tree == nullptr)
		{
			tree = new Tree<T>(val);
		}
		else {
			if (tree->value >= val)
			{
				add(val, tree->left);
			}
			else
			{
				add(val, tree->right);
			}
		}
	}

};
char findProffesion(int level, int pos)
{
	if (level == 1)
		return 'E';
	if (findProffesion(level - 1, (pos + 1) / 2) == 'D')
		return (pos % 2) == 1 ? 'D' : 'E';
	return (pos % 2) == 1 ? 'E' : 'D';
}
string findProfession(int level, int pos) {
	return findProffesion(level, pos) == 'E' ? "Engineer" : "Doctor";
}