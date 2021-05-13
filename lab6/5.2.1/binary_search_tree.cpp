#include "binary_search_tree.h"

void BinarySearchTree::add(int _data, node **_node)
{
	if (*_node == nullptr)
	{
		*_node = new node;
		(*_node)->data = _data;
	}

	else
	{
		if (_data < (*_node)->data)
		{
			add(_data, &((*_node)->left));
		}

		else if (_data > (*_node)->data)
		{
			add(_data, &((*_node)->right));
		}
	}
	return;
}
void BinarySearchTree::get(std::ostream &out, node *_node) const
{
	if (_node->left)
		get(out, _node->left);
	out << _node->data << " ";
	if (_node->right)
		get(out, _node->right);
	return;
}

void BinarySearchTree::get_value(node *_node, std::vector<int> &temp) const
{
	if (_node->left)
		get_value(_node->left, temp);
	temp.push_back(_node->data);
	if (_node->right)
		get_value(_node->right, temp);
	return;
}


std::ostream& operator<<(std::ostream &out, const BinarySearchTree &tree)
{
	tree.get(out, tree.root);
	return out;
}

const BinarySearchTree operator+(BinarySearchTree &lv, const BinarySearchTree &rv)
{
	/* TODO:
	- make lv rv const
	- return new tree, neither lv nor rv
	- new tree must be copied from lv (create copy in tree class)
	*/
	std::vector <int> temp;
	rv.get_value(rv.root, temp);
	for (auto i:temp) lv.add(i, &lv.root);
	return lv;
}
