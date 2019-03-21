// Treap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <functional>
#include <iostream>


struct Node
{
	Node* left;
	Node* right;
	int key, priority;

	Node(int key) :
		key(key),
		priority(rand() % 100),
		left(nullptr),
		right(nullptr)
	{

	}
};

Node* left_rotate(Node* root)
{
	Node* x = root->right;
	Node* t = x->left;
	x->left = root;
	root->right = t;
	return x;
}

Node* right_rotate(Node* root)
{
	Node* x = root->left;
	Node* t = x->right;
	x->right = root;
	root->left = t;
	return x;
}

Node* insert(int key, Node* root)
{
	if (root == nullptr)
	{
		root = new Node(key);
		return root;
	}

	if (key < root->key) 
	{
		root->left = insert(key, root->left);
		if (root->priority > root->left->priority) root = right_rotate(root);
	}
	else if (key > root->key)
	{
		root->right = insert(key, root->right);
		if (root->priority > root->right->priority) root = left_rotate(root);
	}
	return root;
}

void travese_tree(Node* root, std::function<void(Node*)> func)
{
	if (root == nullptr) return;
	travese_tree(root->left, func);
	func(root);
	travese_tree(root->right, func);
}

void print_node(Node* root)
{
	std::cout << "(" << root->key << ", " << root->priority << ") ";
}

Node* search(Node* root, int key)
{
	if (root == nullptr) return nullptr;
	if (root->key == key) return root;
	if (root->key < key) return search(root->right, key);
	else return search(root->left, key);
}

Node* get_successer(Node* root)
{
	Node* tmp = root->right;
	while (tmp->left != nullptr)
	{
		tmp = tmp->left;
	}
	return tmp;
}

Node* delete_node(Node* root, int key)
{

	if (root == nullptr) return nullptr;


	if (key < root->key)
	{
		root->left = delete_node(root->left, key);
		return root;
	}
	else if (key > root->key)
	{
		root->right = delete_node(root->right, key);
		return root;
	}
	else
	{
		//has no child
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			return nullptr;
		}
		else if (root->left == nullptr) //has right child
		{
			Node* right = root->right;
			delete root;
			return right;
		}
		else if (root->right == nullptr) //has left child
		{
			Node* left = root->left;
			delete root;
			return left;
		}
		else //has 2 child
		{
			Node* node = get_successer(root);
			root->key = node->key;						
			root->right = delete_node(root->right, node->key);
			return root;
		}
	}

	
}


int main()
{
	srand(0);
	Node* root = nullptr;
	root = insert(1, root);
	root = insert(2, root);
	root = insert(23, root);
	root = insert(5, root);
	root = insert(7, root);
	root = insert(3, root);
	root = insert(4, root);
	root = insert(6, root);

	travese_tree(root, print_node);
	Node* node = search(root, 10);
	std::cout << "\n " << (node == nullptr);
	node = search(root, 2);
	std::cout << "\n " << (node == nullptr);
	node = search(root, 6);
	std::cout << "\n " << (node == nullptr);

	delete_node(root, 5);
	std::cout << "\n";
	travese_tree(root, print_node);


	system("pause");
	return 0;
}

