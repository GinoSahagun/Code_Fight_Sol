
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

bool isThereSubTree(Tree<int> *t1, Tree<int> *t2)
{
	std::queue<Tree<int> *> q1;
	std::queue<Tree<int> *> q2;

	q2.push(t2);
	q1.push(t1);

	while (!q2.empty() && !q1.empty())
	{
		Tree<int> *curl = q1.front();
		q1.pop();
		Tree<int> *cur = q2.front();
		q2.pop();

		if (cur == nullptr && curl != nullptr)
			return false;
		if (cur != nullptr && curl == nullptr)
			return false;

		if (cur != nullptr && curl != nullptr)
			if (curl->value != cur->value)
				return false;
		if (curl) {
			if (curl->left)
				q1.push(curl->left);
			else
				q1.push(nullptr);
			if (curl->right)
				q1.push(curl->right);
			else
				q1.push(nullptr);
		}
		if (cur) {
			if (cur->left)
				q2.push(cur->left);
			else
				q2.push(nullptr);
			if (cur->right)
				q2.push(cur->right);
			else
				q2.push(nullptr);
		}
	}

	return q1.size() + q2.size() == 0;

}
bool isSubtree(Tree<int> * t1, Tree<int> * t2) {



	if (t1 == nullptr || t2 == nullptr)
		return true;
	std::queue<Tree<int> *> q1;
	Tree<int> *temp = nullptr;

	q1.push(t1);

	while (!q1.empty())
	{

		temp = q1.front();
		q1.pop();
		if (temp->value == t2->value)
			if (isThereSubTree(temp, t2))
				return true;

		if (temp->left)
			q1.push(temp->left);
		if (temp->right)
			q1.push(temp->right);
	}

	return false;




}
