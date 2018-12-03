#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node* next;
}

struct SinglyLinkList
{
	Node* head;
	Node* tail;
}

SinglyLinkList* CreateList()
{
	SinglyLinkList* list = new SinglyLinkList();
	list.head = list.tail = null;
}

bool EmptyList(SinglyLinkList& list)
{
	return list.head == null;
}

int TopFront(SinglyLinkList& list)
{
	if(EmptyList(list)){
		cout << "Empty list";
		return 0;
	}
	
	return list.head->key;
}

void PopFront(SinglyLinkList& list)
{
	if(EmptyList(list))
	{
		cout << "Empty list";
		return;
	}
	
	if(list.head == list.tail)
	{
		delete list.head;
	}
	else 
	{
		Node* p = list.head;
		list.head = list.head->next;
		delete p;
	}
}

void PushFront(int key, SinglyLinkList& list)
{
	Node* node = new Node();
	node->key = key;
	node->next = list.head;
	
	if(list.head == null)
	{
		list.head = list.tail = node;
	}
	else
	{
		list.head = node;
	}
}

void printList(SinglyLinkList& list)
{
	
	
}


int main()
{
		
}