

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

template <typename T>
string NumberToString(T Number)
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}


void traverse(Tree<int>* root, std::vector<int> &s)
{
	queue<Tree<int>*> q;

	if (root) {
		q.push(root);

	}
	while (!q.empty())
	{
		const Tree<int> *temp_node = q.front();
		q.pop();
		s.push_back(temp_node->value);
		cout << temp_node->value << "\n";

		if (temp_node->left) {
			q.push(temp_node->left);
		}
		if (temp_node->right) {
			q.push(temp_node->right);
		}
	}
}
int left(int i) {
	return 2 * i + 1;
}
int right(int i) {
	return 2 * i + 2;
}
int parent(int i) {
	return (i - 1) / 2;
}

int main()
{
	//vector<string> keywords;
	//keywords.push_back("he");
	//keywords.push_back("she");
	//keywords.push_back("hers");
	//keywords.push_back("his");

	//string text = "ahishers";

	//vector<int> states = FindAllStates(text, keywords);
	

	std::vector<int> a = { 10, 3, 12, 4, 2, 9, 13, 0, 8, 11, 1, 7, 5, 6 };



	return 0;
}

