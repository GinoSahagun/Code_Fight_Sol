

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

ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
	int size = 0;
	ListNode<int> *cur = l;
	ListNode<int> *prev = nullptr;
	while (cur)
	{

		cur = cur->next;
		size++;
	}

	if (n > size && n == 0)
	{
		return l;
	}
	int stop = size - n;
	cur = l;
	for (int i = 0; i < stop; i++)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = nullptr;
	prev = cur;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = l;
	return prev;
}