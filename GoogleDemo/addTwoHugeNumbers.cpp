
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

ListNode<int> * addTwoHugeNumbersWrap(ListNode<int> * a, ListNode<int> * b, int carry) {
	ListNode<int> *cur;
	div_t temp;
	int over = carry;
	if (a == nullptr && b == nullptr)
	{
		if (carry >= 1)
		{
			cur = new ListNode<int>(carry);
			carry = 0;
			cur->next = addTwoHugeNumbersWrap(nullptr, nullptr, carry);
			return cur;
		}
		else
		{
			return nullptr;
		}
	}
	if (a == nullptr)
	{
		ListNode<int> *p;
		temp.quot = b->value + over;
		temp.rem = (b->value) % 10000;
		if (temp.quot >= 10000)
		{
			temp.quot /= 10000;
			temp.rem = carry + temp.rem;
			if (temp.rem >= 10000)
				temp.rem %= 10000;
			p = new ListNode<int>(temp.rem);
			over = temp.quot;
		}
		else
		{
			p = new ListNode<int>(temp.quot);
			over = 0;
		}

		p->next = addTwoHugeNumbersWrap(nullptr, b->next, over);
		return p;
	}
	if (b == nullptr)
	{
		ListNode<int> *p;
		temp.quot = a->value + carry;
		temp.rem = (a->value) % 10000;
		if (temp.quot >= 10000)
		{
			temp.quot /= 10000;
			temp.rem = carry + temp.rem;
			if (temp.rem >= 10000)
				temp.rem %= 10000;
			p = new ListNode<int>(temp.rem);
			over = temp.quot;
		}
		else
		{
			p = new ListNode<int>(temp.quot);
			over = 0;
		}

		p->next = addTwoHugeNumbersWrap(a->next, nullptr, over);
		return p;
	}
	temp.quot = a->value + b->value + carry;
	temp.rem = (a->value + b->value + carry) % 10000;
	if (temp.quot >= 10000)
	{
		temp.quot /= 10000;
		cur = new ListNode<int>(temp.rem);
		over = temp.quot;
	}
	else
	{
		cur = new ListNode<int>(temp.quot);
		over = 0;
	}
	cur->next = addTwoHugeNumbersWrap(a->next, b->next, over);
	return cur;
}
//ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
//	ListNode<int> *cura = reverseList(a);
//	ListNode<int> *curb = reverseList(b);
//	return reverseList(addTwoHugeNumbersWrap(cura, curb, 0));
//}