#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
using namespace std;
// Definition for singly-linked list:
template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	ListNode() : value(0), next(nullptr) {}
	T value;
	ListNode *next;
};

bool isListPalindrome(ListNode<int> * l) {

	ListNode<int> * cur = l;
	std::stack<int> items;
	while (cur != nullptr)
	{
		items.push(cur->value);
		cur = cur->next;
	}
	int temp = 0;
	cur = l;
	for (int i = 0; i < items.size(); i++)
	{
		temp = items.top();
		items.pop();
		if (temp != cur->value)
		{
			return false;
		}
		else
		{
			cur = cur->next;
		}
	}

	return true;
}