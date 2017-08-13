

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
//Reverse a Singly Linked List
ListNode<int> * reverseList(ListNode<int> * l) {

	ListNode<int> *cur = nullptr;
	ListNode<int> *prev;
	while (l)
	{
		prev = l->next;
		l->next = cur;
		cur = l;
		l = prev;

	}
	return cur;

}
//attach new Nodes onto end of List	
void push(ListNode<int> * l, int val)
{
	ListNode<int> *p = new ListNode<int>(val);
	ListNode<int> *cur = l;
	while (cur->next != nullptr)
		cur = cur->next;
	cur->next = p;
}





int main()
{


	return 0;
}

