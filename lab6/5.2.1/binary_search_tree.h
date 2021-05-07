#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SERACH_TREE_H
#include <iostream>
#include <vector>

class BinarySearchTree
{
public:
	struct node
	{
		int data = 0;
		node *left = nullptr;
		node *right = nullptr;
	};
	node* root = nullptr;
	void add(int _data, node** _node);
	void get(std::ostream &out, node* _node) const;

	void get_value(node *_node, std::vector <int> &temp) const;

	friend std::ostream& operator<<(std::ostream &out, const BinarySearchTree &tree);
	friend const BinarySearchTree operator+(BinarySearchTree &lv, const BinarySearchTree &rv);
};

#endif // BINARY_SEARCH_TREE.H