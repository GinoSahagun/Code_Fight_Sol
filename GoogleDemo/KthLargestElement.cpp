

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
void kthLargestInBST(Tree<int> * t, int &k, int &z) {

	if (t == nullptr || z >= k)
		return;
	kthLargestInBST(t->left, k, z);
	z++;
	if (z == k) {
		k = t->value;
		if (z <= k)
			z = k + 1;
	}
	kthLargestInBST(t->right, k, z);



}
int kthLargestInBST(Tree<int> * t, int k) {

	int c = 0;
	kthLargestInBST(t, k, c);
	return k;


}