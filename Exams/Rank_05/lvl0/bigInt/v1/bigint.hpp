#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

class bigint
{
	private:
		std::string		_digits;

		std::string		addStrings(const std::string &a, const std::string &b) const;
	public:
		bigint();
		bigint(unsigned int nbr);
		bigint(const bigint &nbr);

		bigint		operator+(const bigint &other) const;
		bigint		&operator+=(const bigint &other);

		bool		operator==(const bigint &other) const;
		bool		operator!=(const bigint &other) const;
		bool		operator<(const bigint &other) const;
		bool		operator>(const bigint &other) const;
		bool		operator<=(const bigint &other) const;
		bool		operator>=(const bigint &other) const;

		bigint		operator<<(unsigned int toShift) const;
		bigint		operator>>(unsigned int toShift) const;
		bigint		&operator<<=(unsigned int toShift);
		bigint		&operator>>=(unsigned int toShift);

		bigint		&operator<<=(const bigint &toShift);
		bigint		&operator>>=(const bigint &toShift);

		bigint		&operator++();
		bigint		operator++(int);

		std::string	getDigits() const;
};

std::ostream	&operator<<(std::ostream &out, const bigint &nbr);

#endif
