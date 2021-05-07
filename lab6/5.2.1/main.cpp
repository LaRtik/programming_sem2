#include <iostream>

#include "binary_search_tree.h"

using namespace std;

int main()
{
	BinarySearchTree tree;
	tree.add(0, &tree.root);
	tree.add(1, &tree.root);
	tree.add(-1, &tree.root);
	tree.add(-10, &tree.root);
	cout << tree << endl;
	
	BinarySearchTree tree2;
	tree2.add(1, &tree2.root);
	tree2.add(9, &tree2.root);
	tree2.add(10, &tree2.root);
	tree2.add(12, &tree2.root);
	cout << tree2 << endl;

	cout << tree + tree2;
	return 0;
}