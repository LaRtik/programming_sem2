#include <iostream>
#include <vector>
#include <assert.h>

#include "binary_search_tree.h"


using namespace std;

void test()
{
	BinarySearchTree tree;
	tree.add(-1, &tree.root);
	tree.add(-2, &tree.root);
	tree.add(10, &tree.root);
	tree.add(-1, &tree.root);
	tree.add(7, &tree.root);
	vector <int> temp;
	tree.get_value(tree.root, temp);
	assert(temp.size() == 4);
	assert(temp[0] == -2);
	assert(temp[1] == -1);
	assert(temp[2] == 7);
	assert(temp[3] == 10);
}

int main()
{
	test();
	return 0;
}