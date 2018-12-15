// SinglyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* pNext;
};

struct SLList {
	Node* head;
	Node* tail;
};
SLList list;

bool isEmpty()
{
	return list.head == nullptr;
}

void pushFont(int value)
{
	if (isEmpty())
	{
		list.head = new Node();
		list.head->value = value;
		list.head->pNext = nullptr;
		list.tail = list.head;
	}
	else {
		Node* p = new Node();
		p->pNext = list.head;
		p->value = value;
		list.head = p;
	}
}

int topFront()
{
	if (isEmpty())
	{
		return INT32_MAX;
	}
	else {
		return list.head->value;
	}
}

void popFront()
{
	if (isEmpty())
	{
		return;
	}
	if (list.head == list.tail)
	{
		delete list.head;
		list.head = list.tail = nullptr;
	}
	else
	{
		Node* p = list.head;
		list.head = list.head->pNext;
		delete p;
	}
}


void pushBack(int value)
{
	if (isEmpty())
	{
		list.head = list.tail = new Node();
		list.head->value = value;
		list.head->pNext = nullptr;
	}
	else
	{
		list.tail->pNext = new	Node();
		list.tail = list.tail->pNext;
		list.tail->value = value;
		list.tail->pNext = nullptr;
	}
}

void popBack()
{
	if (isEmpty())
	{
		return;
	}
	if (list.head == list.tail)
	{
		delete list.head;
		list.head = list.tail = nullptr;
	}
	else
	{
		Node* p = list.head;
		while (p->pNext != list.tail)
		{
			p = p->pNext;
		}

		delete list.tail;
		list.tail = p;
		list.tail->pNext = nullptr;

	}
}

int topBack()
{
	if (isEmpty())
		return INT32_MIN;
	return list.tail->value;
}

Node* Find(int value)
{
	if (isEmpty())
		return nullptr;

	if (list.head->value == value)
		return list.head;

	Node* p = list.head->pNext;
	while (p != nullptr && p->value != value)
	{
		p = p->pNext;
	}

	return p;
}

void Erase(int value)
{
	if (isEmpty())
		return;

	if (list.head == list.tail && list.head->value == value)
	{
		delete list.head;
		list.head = list.tail = nullptr;
		return;
	}

	if (list.head->value == value)
	{
		Node* p = list.head->pNext;
		delete list.head;
		list.head = p;
		return;
	}

	

	Node* pre = list.head;
	Node* p = list.head->pNext;
	while (p->value != value && p != list.tail)
	{
		pre = p;
		p = p->pNext;
	}

	if (p != list.tail)
	{
		pre->pNext = p->pNext;
		delete p;
		return;
	}

	if (list.tail->value == value)
	{	
		delete list.tail;
		list.tail = pre;
		list.tail->pNext = nullptr;
		return;
	}
}

void addBefore(Node* node, int value)
{
	if (node == list.head)
	{
		Node* p = new Node();
		p->value = value;
		p->pNext = list.head;
		list.head = p;
		return;
	}

	Node* pre = list.head;
	while (pre->pNext != node && pre->pNext != nullptr)
	{
		pre = pre->pNext;
	}

	if (pre->pNext == node)
	{
		Node* p = new Node();
		p->value = value;
		p->pNext = node;
		pre->pNext = p;
	}
}

void addAfter(Node* node, int value)
{
	Node* p = list.head;
	while (p != node && p != nullptr)
	{
		p = p->pNext;
	}

	if (p == node)
	{
		Node* add = new Node();
		add->value = value;
		add->pNext = node->pNext;
		node->pNext = add;
		if (node == list.tail)
		{
			list.tail = add;
		}
	}
}


void destroyList()
{
	if (!isEmpty())
	{
		Node* p = list.head;
		Node* next;

		while (p!=nullptr)
		{
			next = p->pNext;
			delete p;
			p = next;
		}
	}
}

void printList()
{
	if (isEmpty())
	{
		cout << "\nList empty.";
		return;
	}

	Node* p = list.head;
	cout << "\nList: ";
	while (p != nullptr)
	{
		cout << p->value << " ";
		p = p->pNext;
	}
}





int main()
{
	//pushFont(1);
	pushBack(1);
	
	pushBack(3);
	pushBack(2);
	printList();
	addAfter(Find(2), 0);
	printList();
	

	destroyList();

	system("pause");
    return 0;
}

