#include "stdafx.h"
#include "AVLTree.h"

int max(int a, int b) { return a > b ? a : b; }

int heigh(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return 1 + max(heigh(node->left), heigh(node->right));
}



Node* left_rotate(Node* node)
{
	Node* dinh = node;
	Node* giua = node->right;

	dinh->right = giua->left;
	giua->left = dinh;

	giua->height = heigh(giua);
	dinh->height = heigh(dinh);

	return giua;
}

Node* right_rotate(Node* node)
{
	Node* dinh = node;
	Node* giua = node->left;

	dinh->left = giua->right;
	giua->right = dinh;

	giua->height = heigh(giua);
	dinh->height = heigh(dinh);

	return giua;
}

int get_balance(Node* root)
{
	return heigh(root->left) - heigh(root->right);
}


bool is_AVLTree(Node* root)
{
	if (root == nullptr)
		return true;

	int balance = get_balance(root);
	if (balance >= 2 || balance <= -2)
		return false;

	return is_AVLTree(root->left) && is_AVLTree(root->right);
}

void _traverse(Node* root, std::function<void(Node*)> cb)
{
	if (root == nullptr)
		return;
	_traverse(root->left, cb);
	cb(root);
	_traverse(root->right, cb);
}

void free_node(Node* node)
{
	if (node == nullptr)
		return;
	free_node(node->left);
	free_node(node->right);
	delete(node);
}

AVLTree::AVLTree():
	_root(nullptr)
{
}


AVLTree::~AVLTree()
{
	free_node(_root);
}

void AVLTree::insert(int data)
{
	_root = _insert(_root, data);
}

void AVLTree::traverse(std::function<void(Node*)> call_back)
{
	_traverse(_root, call_back);
}

Node * AVLTree::_insert(Node * root, int data)
{
	if (root == nullptr)
		return new Node(data);

	if (data < root->data)
		root->left = _insert(root->left, data);
	else if (data > root->data)
		root->right = _insert(root->right, data);
	else
		return root;

	root->height = 1 + max(heigh(root->left), heigh(root->right));
	int balance = heigh(root->left) - heigh(root->right);


	if (balance >= 2 && data < root->left->data) //LL
	{
		root = right_rotate(root);
	}
	else if (balance <= -2 && data > root->right->data) //RR
	{
		root = left_rotate(root);
	}
	else if (balance >= 2 && data > root->left->data) //LR
	{
		root->left = left_rotate(root->left);
		root = right_rotate(root);
	}
	else if (balance <= -2 && data < root->right->data) //RL
	{
		root->right = right_rotate(root->right);
		root = left_rotate(root);
	}


	return root;
}
