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
// Definition for singly-linked list:
template<typename T>
struct ListNode {
	ListNode(const T &v) : value(v), next(nullptr) {}
	ListNode() : value(0), next(nullptr) {}
	T value;
	ListNode *next;

};

//Attach a reversed singly list
ListNode<int> * reverseList(ListNode<int> * &head, ListNode<int> * l, ListNode<int> * end) {

	ListNode<int> *cur = nullptr;
	ListNode<int> *prev = nullptr;
	ListNode<int> *temp = l;
	while (temp)
	{
		prev = temp->next;
		temp->next = cur;
		cur = temp;
		temp = prev;

	}
	if (head->next == nullptr)
		head = cur;
	else {
		temp = head;
		while (temp->next != nullptr)
			temp = temp->next;

		temp->next = cur;

	}
	return cur;
}


ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
	if (k <= 1)
		return l;

	int temp = 1;
	ListNode<int> * cur = l;
	ListNode<int> * beg = l;
	while (cur)
	{
		cur = cur->next;
		temp++;
		if (cur == nullptr)
		{
			cur = l;
			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = beg;
			break;
		}
		if (temp % k == 0)
		{
			ListNode<int> *att = cur->next;
			cur->next = nullptr;
			reverseList(l, beg, cur);
			cur = att;
			beg = cur;
			temp++;
		}


	}

	return l;
}