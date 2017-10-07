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
void removeKNode(ListNode<int> * l, int pos = 0)
{
	ListNode<int> * cur = l;
	ListNode<int> * prev = nullptr;
	for (int i = 0; i < pos; i++)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	cur->next = nullptr;
	delete cur;
}
void clearList(ListNode<int> * l, int pos = 0, int size = 0)
{
	ListNode<int> * cur = l;
	for (int i = pos; i < size; i++)
	{
		removeKNode(l, i);
		i--;
		size--;

	}
}