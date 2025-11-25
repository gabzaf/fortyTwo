#include "vect2.hpp"

vect2::vect2(int x, int y)
{
	data[0] = x;
	data[1] = y;
}

vect2::vect2(const vect2 &other)
{
	data[0] = other.data[0];
	data[1] = other.data[1];
}

vect2	&vect2::operator=(const vect2 &other)
{
	
}
