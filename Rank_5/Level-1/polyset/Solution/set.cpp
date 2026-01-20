#include "set.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

set::set(searchable_bag& b)
{
	// Determine if it's array_bag or tree_bag
	searchable_array_bag* arr = dynamic_cast<searchable_array_bag*>(&b);
	if (arr != nullptr)
		bag = new searchable_array_bag(*arr);
	else
		bag = new searchable_tree_bag(*(dynamic_cast<searchable_tree_bag*>(&b)));
}

set::set(const set& other)
{
	searchable_array_bag* arr = dynamic_cast<searchable_array_bag*>(other.bag);
	if (arr != nullptr)
		bag = new searchable_array_bag(*arr);
	else
		bag = new searchable_tree_bag(*(dynamic_cast<searchable_tree_bag*>(other.bag)));
}

set& set::operator=(const set& other)
{
	if (this != &other)
	{
		delete bag;
		searchable_array_bag* arr = dynamic_cast<searchable_array_bag*>(other.bag);
		if (arr != nullptr)
			bag = new searchable_array_bag(*arr);
		else
			bag = new searchable_tree_bag(*(dynamic_cast<searchable_tree_bag*>(other.bag)));
	}
	return (*this);
}

set::~set()
{
	delete bag;
}

void set::insert(int item)
{
	if (!bag->has(item))
		bag->insert(item);
}

void set::insert(int* items, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (!bag->has(items[i]))
			bag->insert(items[i]);
	}
}

void set::print() const
{
	bag->print();
}

void set::clear()
{
	bag->clear();
}

bool set::has(int item) const
{
	return (bag->has(item));
}

searchable_bag& set::get_bag() const
{
	return (*bag);
}