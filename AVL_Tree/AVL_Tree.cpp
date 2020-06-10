// AVL Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AVLTree.h"
#include <iostream>


int main()
{
	AVLTree tree;

	tree.insert(50);
	tree.insert(30);
	tree.insert(40);
	
	std::cout << "AVL: ";
	tree.traverse([](Node* node)->void {std::cout << node->data << " "; });
	std::cout << "\n";

	std::cout << "Is AVL tree: " << is_AVLTree(tree.get_root()) << "\n";


	system("pause");
    return 0;
}

