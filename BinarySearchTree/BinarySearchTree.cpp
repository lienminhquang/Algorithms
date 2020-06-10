// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <functional>

int max(int a, int b)
{
	return a > b ? a : b;
}

struct Node
{
	int _key;
	Node* _left;
	Node* _right;
	Node* _parent;

	Node(int key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{}
};


class BST
{
public:
	BST()
	:_root(nullptr)
	{}

	~BST()
	{
		_free_node(_root);
	}

	void _free_node(Node* node)
	{
		if (node == nullptr)
			return;
		_free_node(node->_left);
		_free_node(node->_right);
		std::cout << "Free: " << node->_key << "\n";
		delete node;
		node = nullptr;
	}

	void delete_node(Node* node)
	{
		//1. Node ko co con
		//2. Node co 1 con
		//3. Node co 2 con

		if (node->_left == nullptr && node->_right == nullptr)
		{
			if (node->_parent->_left == node)
			{
				node->_parent->_left = nullptr;
			}
			else
			{
				node->_parent->_right = nullptr;
			}

			delete node;
			return;
		}
		
		if (node->_right == nullptr)
		{
			node->_key = node->_left->_key;
			delete_node(node->_left);
			return;
		}
		if (node->_left == nullptr)
		{
			node->_key = node->_right->_key;
			delete_node(node->_right);
			return;
		}

		Node* min_node = _find_min(node);
		node->_key = min_node->_key;
		delete_node(min_node);
	}

	void insert(int key) 
	{
		_root = _insert(_root, key);
	}

	int get_min()
	{
		if (_root == nullptr)
			return -_CRT_INT_MAX;

		Node* node = _root;
		while (node->_left != nullptr)
			node = node->_left;
		return node->_key;
	}

	int get_max()
	{
		if (_root == nullptr)
			return _CRT_INT_MAX;

		Node* node = _root;
		while (node->_right != nullptr)
			node = node->_right;
		return node->_key;
	}

	Node* search(int key)
	{
		if (_root == nullptr)
			return nullptr;

		Node* node = _root;
		while (node != nullptr)
		{
			if (node->_key == key)
				return node;

			if (key <= node->_key)
			{
				node = node->_left;
				continue;
			}
			if (key > node->_key)
			{
				node = node->_right;
				continue;
			}
		}

		return nullptr;
	}

	void traverse(std::function<void(Node*)> call_back)
	{
		_traverse(_root, call_back);
	}

	int get_heigh()
	{
		return _get_heigh(_root);
	}


private:

	int _get_heigh(Node* node)
	{
		if (node == nullptr)
			return 0;
		return max(_get_heigh(node->_left) , _get_heigh(node->_right)) + 1;
	}

	void _traverse(Node* node, std::function<void(Node*)> call_back)
	{
		if (node == nullptr)
			return;
		_traverse(node->_left, call_back);
		call_back(node);
		_traverse(node->_right, call_back);
	}
	Node* _find_min(Node* node)
	{
		while (node->_left != nullptr)
			node = node->_left;
		return node;
	}

	Node* _insert(Node* root, int key)
	{
		if (root == nullptr)
		{
			root = new Node(key);		
		} 
		else if (key <= root->_key)
		{
			root->_left = _insert(root->_left, key);
			root->_left->_parent = root;
		}
		else
		{
			root->_right = _insert(root->_right, key);
			root->_right->_parent = root;
		}

		return root;
	}

private:
	Node* _root;
};

void print_node(Node* node)
{
	std::cout << node->_key << " ";
}

int main()
{
	BST tree;

	tree.insert(49);
	tree.insert(79);
	tree.insert(46);
	tree.insert(41);
	tree.insert(20);

	std::cout << "Max: " << tree.get_max() << "\n";
	std::cout << "Min: " << tree.get_min() << "\n";
	Node* found = tree.search(100);
	if(found == nullptr)
		std::cout << "Search key = 100:" << " Not found !!1\n";
	std::cout << "Search key = 46: " << tree.search(46)->_key << "\n";

	tree.traverse(print_node);
	std::cout << "\n";
	tree.delete_node(tree.search(46));

	tree.traverse(print_node);
	std::cout << "\n";

	std::cout << "Height = " << tree.get_heigh() << "\n";

	//tree.~BST();

	system("pause");
    return 0;
}

