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

ListNode<int> * removeKFromList(ListNode<int> * l, int k) {

	ListNode<int> *cur = l;
	ListNode<int> *prev = nullptr;
	if (l == nullptr)
	{
		return l;
	}
	if (l->value == k)
	{
		prev = cur;
		cur = l->next;
		l = l->next;
		prev->next = nullptr;
		delete prev;
		return removeKFromList(l, k);
	}

	while (cur != nullptr)
	{
		if (cur->value == k)
		{
			prev->next = cur->next;
			cur->next = nullptr;
			delete cur;
			return removeKFromList(l, k);
		}
		prev = cur;
		cur = cur->next;

	}

	return l;
}