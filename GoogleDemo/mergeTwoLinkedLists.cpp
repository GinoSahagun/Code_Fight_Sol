//
//#include <iostream>
//#include <string.h>
//#include <sstream>
//#include <vector>
//#include <set>
//#include <stack>
//#include <map>
//using namespace std;
//// Definition for singly-linked list:
//template<typename T>
//struct ListNode {
//	ListNode(const T &v) : value(v), next(nullptr) {}
//	ListNode() : value(0), next(nullptr) {}
//	T value;
//	ListNode *next;
//
//};
////Reverse a Singly Linked List
//ListNode<int> * reverseList(ListNode<int> * l) {
//
//	ListNode<int> *cur = nullptr;
//	ListNode<int> *prev;
//	while (l)
//	{
//		prev = l->next;
//		l->next = cur;
//		cur = l;
//		l = prev;
//
//	}
//	return cur;
//
//}
////attach new Nodes onto end of List	
//void push(ListNode<int> * l, int val)
//{
//	ListNode<int> *p = new ListNode<int>(val);
//	ListNode<int> *cur = l;
//	while (cur->next != nullptr)
//		cur = cur->next;
//	cur->next = p;
//}
//
//ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
//	ListNode<int> *curl1 = l1;
//	ListNode<int> *curl2 = l2;
//	bool s = false;
//	int temp = -1;
//	if (curl2 == nullptr && curl1 != nullptr)
//	{
//		temp = curl1->value;
//		curl1 = curl1->next;
//		s = true;
//	}
//	else if (curl1 != nullptr && curl1->value <= curl2->value) {
//		temp = curl1->value;
//		curl1 = curl1->next;
//		s = true;
//	}
//	else if (curl2 != nullptr) {
//		temp = curl2->value;
//		curl2 = curl2->next;
//		s = true;
//	}
//
//	ListNode<int> *head = new ListNode<int>(temp);
//	if (s == false)
//	{
//		head = nullptr;
//	}
//	ListNode<int> *tail = head;
//
//	while (curl1 != nullptr || curl2 != nullptr)
//	{
//		if (curl1 && curl2)
//		{
//			if (curl1->value <= curl2->value) {
//				push(head, curl1->value);
//				tail = tail->next;
//				curl1 = curl1->next;
//			}
//			else {
//				push(head, curl2->value);
//				tail = tail->next;
//				curl2 = curl2->next;
//			}
//		}
//		else if (curl1)
//		{
//			tail->next = curl1;
//			break;
//		}
//		else {
//			tail->next = curl2;
//			break;
//		}
//
//
//	}
//
//	return head;
//}