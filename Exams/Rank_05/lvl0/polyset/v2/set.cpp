#include "set.hpp"

set::set(searchable_bag &_bag) : bag(_bag){}

set::set(const set &other) : bag(other.bag){}

set	&set::operator=(const set &other)
{
	this->bag = other.bag;
	return (*this);
}

set::~set();

void	set::insert(int item)
{
	if (bag.has(item))
		bag.insert(item);
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

void	set::clear() const
{
	bag.clear();
}

bool	set::has(int value) const
{
	return (bag.has(value));
}

const searchable_bag	&set::get_bag() const
{
	return (bag);
}
