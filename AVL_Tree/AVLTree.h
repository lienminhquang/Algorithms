#pragma once
#include <functional>

struct Node 
{
	int data;
	Node* left;
	Node* right;
	int height;

	Node(int _data)
		:data(_data)
		,left(nullptr)
		,right(nullptr)
		,height(1)
	{}
};


bool is_AVLTree(Node* root);



class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	void insert(int data);

	void traverse(std::function<void(Node*)> call_back);

	Node* get_root() { return _root; }

private:
	Node* _insert(Node* root, int data);

private:
	Node* _root;
};

