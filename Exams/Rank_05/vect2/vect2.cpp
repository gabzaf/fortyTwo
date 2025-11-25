#include "vect2.hpp"

vect2::vect2(int x, int y)
{
	_data[0] = x;
	_data[1] = y;
}

vect2::vect2(const vect2 &other)
{
	_data[0] = other._data[0];
	_data[1] = other._data[1];
}

vect2	&vect2::operator=(const vect2 &other)
{
	if (this != other)
	{
		_data[0] = other._data[0];
		_data[1] = other._data[1];
	}
	return (*this);
}

int	&vect2::operator[](int index)
{
	return (_data[index]);
}

const int	&vect2::operator[](int index) const
{
	return (_data[index]);
}

vect2		vect2::operator+(const vect2 &other) const
{
	return (vect2(_data[0] + other._data[0], _data[1] + other._data[1]);
}

vect2		vect2::operator-(const vect2 &other) const
{
	return (vect2(_data[0] - other._data[0], _data[1] - other._data[1]);
}

vect2		vect2::operator*(int carry) const
{
	return (vect2(_data[0] * carry, _data[1] * carry));
}

vect2		vect2::operator+()
{
	return (vect2(+_data[0], +_data[1]));
}

vect2		operator-()
{
	return (vect2(+_data[0], +_data[1]));
}

vect2		operator+=(const vect2 &other)
{
	_data[0] += other._data[0];
	_data[1] += other._data[1];
	return (*this);
}

vect2		operator-=(const vect2 &other)
{
	_data[0] -= other._data[0];
	_data[1] -= other._data[1];
	return (*this);
}

vect2		operator*=(int carry);

vect2		operator++(int);

vect2		&operator++();

vect2		operator--(int);

vect2		&operator--();

bool		operator==(const vect2 &other) const;

bool		operator!=(const vect2 &other) const;

