#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag()
{
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other)
{
}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
	if (this != &other)
	{
		tree_bag::operator=(other);
	}
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag()
{
}

bool searchable_tree_bag::has(int item) const
{
	return (search_node(tree, item));
}

bool searchable_tree_bag::search_node(node* current, int item)
{
	if (current == nullptr)
		return (false);
	
	if (item == current->value)
		return (true);
	
	if (item < current->value)
		return (search_node(current->l, item));
	else
		return (search_node(current->r, item));
}