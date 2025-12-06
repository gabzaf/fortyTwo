#include "set.hpp"



set::set(searchable_bag &bag) : bag(bag){}

set::set(const set &other) : bag(other.bag){}

set &set::operator=(const set &other)
{
	if (this != &other)
		this->bag = other.bag;
	return (*this);
}

set::~set(){}

void	set::insert(int value)
{
	if (!bag.has(value))
		bag.insert(value);
}

void	set::insert(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!bag.has(array[i]))
			bag.insert(array[i]);
	}
}

void	set::print() const
{
	bag.print();
}

void	set::clear()
{
	bag.clear();
}

bool	set::has(int value) const
{
	return (bag.has(value));
}

searchable_bag &set::get_bag() const
{
	return bag;
}
