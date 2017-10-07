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
			if (tree->left == nullptr)
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
bool areMirrorImages(Tree<int> *l, Tree<int> *r)
{
	std::queue<Tree<int> *> left;
	std::queue<Tree<int> *> right;

	if (l && r)
	{
		left.push(l);
		right.push(r);
	}
	else if (l == nullptr && r == nullptr)
		return true;
	else
		return false;

	while (!left.empty() && !right.empty())
	{
		const Tree<int> *currentRight = right.front();
		const Tree<int> *currentLeft = left.front();
		right.pop();
		left.pop();
		if (currentLeft == nullptr && currentRight == nullptr)
			continue;
		if (currentLeft == nullptr || currentRight == nullptr)
			return false;
		if (currentLeft->value != currentRight->value)
			return false;

		if (currentLeft->left)
			left.push(currentLeft->left);
		else
			left.push(nullptr);
		if (currentLeft->right)
			left.push(currentLeft->right);
		else
			left.push(nullptr);
		if (currentRight->right)
			right.push(currentRight->right);
		else
			right.push(nullptr);
		if (currentRight->left)
			right.push(currentRight->left);
		else
			right.push(nullptr);

	}

	return left.size() + right.size() == 0;
}

bool isTreeSymmetric(Tree<int> * t) {

	if (t != nullptr)
		return areMirrorImages(t->left, t->right);

	return true;


}