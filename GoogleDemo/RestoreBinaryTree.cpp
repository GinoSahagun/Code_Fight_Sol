

#include <iostream>
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
int searchInOrder(std::vector<int> inorder, int start, int end, int value)
{
	for (int i = start; i <= end; i++)
	{
		if (inorder[i] == value)
			return i;
	}



}

Tree<int> * buildTree(std::vector<int> in, std::vector<int> pre, int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	/* Pick current node from Preorder traversal using preIndex
	and increment preIndex */
	Tree<int> *tNode = new Tree<int>(pre[preIndex]);
	preIndex++;
	/* If this node has no children then return */
	if (inStrt == inEnd)
		return tNode;

	/* Else find the index of this node in Inorder traversal */
	int inIndex = searchInOrder(in, inStrt, inEnd, tNode->value);

	/* Using index in Inorder traversal, construct left and
	right subtress */

	int newEnd = inIndex - 1;
	int newStart = inIndex + 1;

	tNode->left = buildTree(in, pre, inStrt, newEnd);
	tNode->right = buildTree(in, pre, newStart, inEnd);

	return tNode;
}

Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
	Tree<int> * t = buildTree(inorder, preorder, 0, inorder.size() - 1);
	return t;
}