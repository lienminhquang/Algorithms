
/*
ID: minhqua3
TASK: beads
LANG: C++
*/


#include "stdafx.h"

#include <string>
#include <iostream>
#include <fstream>

struct  Node
{
	int size;
	Node* next;

	Node(int s):
		size(s),
		next(nullptr)
		{}
};

Node* head = nullptr;
Node* tail = nullptr;

void add(int size)
{
	Node* node = new Node(size);
	if (head == nullptr)
		head = tail = node;
	else
	{
		tail->next = node;
		tail = node;
	}
}

void free_list()
{


	Node* next = nullptr;
	while (head != nullptr)
	{
		std::cout << head->size <<" ";
		next = head->next;
		delete head;
		head = next;
	}
}


int main()
{
	std::ofstream fout("beads.out");
	std::ifstream fin("beads.in");

	int N = 0;
	std::string beads;
	fin >> N >>  beads;

	
	char c_cur = beads[0];

	int i = 0;

	while (beads[i] == c_cur || beads[i] == 'w')
		++i;
	if (i == N) i = 0;
	c_cur = beads[i];
	int start = i;
	bool loop = false;

	int len = 0;
	 
	do {

		int tong = 0;
		

		int k = i;

		while (tong < beads.size() && (beads[k] == c_cur || beads[k] == 'w'))
		{
			tong++;
			++k;
			if (k == N) k = 0;					
		}	
		add(tong);
		len += tong;

		//if (k < i) break;
		i = k;
		c_cur = beads[i];		
	} while (len < beads.size());

	Node* node = head;
	int max = 0;
	Node* pre = tail == head ? nullptr : tail;


	while (node != nullptr)
	{
		if (pre != nullptr)
		{
			if (max < (node->size + pre->size)) max = node->size + pre->size;
			pre = node;
			node = node->next;
		}
		else
		{
			max = node->size;
			node = node->next;
		}	
	}

	fout << max << std::endl;

	free_list();
	system("pause");
    return 0;
}

