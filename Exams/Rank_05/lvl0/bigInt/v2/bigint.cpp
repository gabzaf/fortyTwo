#include "bigint.hpp"

bigint::bigint() : _digits("0"){}

bigint::bigint(unsigned int nbr)
{
	if (nbr == 0)
	{
		_digits = "0";
		return ;
	}
	else
	{
		std::ostringstream ss;
		ss << nbr;
		_digits = ss.str();
		std::reverse(_digits.begin(), _digits.end());
	}
}

bigint::bigint(const bigint &nbr)
{
	*this = nbr;
}

std::string		bigint::addStrings(const std::string &a, const std::string &b) const
{
	std::string	res;
	int		len = std::max(a.size(), b.size());
	int		carry = 0;

	for (int i = 0; i < len || carry; i++)
	{
		int digitA = i < (int)a.size() ? a[i] - '0' : 0;	
		int digitB = i < (int)b.size() ? b[i] - '0' : 0;
		int sum = digitA + digitB + carry;
		res.push_back((sum % 10) + '0');
		carry = sum / 10;
	}
	return (res);
}

bigint			bigint::operator+(const bigint &other) const
{
	bigint res = *this;
	res._digits = addStrings(res._digits, other._digits);
	return (res);
}

bigint			&bigint::operator+=(const bigint &other)
{	
	_digits = addStrings(_digits, other._digits);
	return (*this);
}

bool			bigint::operator==(const bigint &other) const
{
	return (_digits == other._digits);
}

bool			bigint::operator!=(const bigint &other) const
{
	return (!(_digits == other._digits));
}

bool			bigint::operator<(const bigint &other) const
{
	if (_digits.size() != other._digits.size())
		return (_digits.size() < other._digits.size());
	for (int i = _digits.size() - 1; i >= 0; i--)
	{
		if (_digits[i] != other._digits[i])
			return (_digits[i] < other._digits[i]);
	}
	return (false);
}

bool			bigint::operator>(const bigint &other) const
{
	return (other < *this);
}

bool			bigint::operator<=(const bigint &other) const
{
	return (!(*this > other));
}

bool			bigint::operator>=(const bigint &other) const
{
	return (!(*this < other));
}

bigint			bigint::operator<<(unsigned int toShift) const
{
	bigint res = *this;
	if (toShift == 0)
		return (res); 
	res._digits.insert(res._digits.begin(), toShift, '0');
	return (res);
}

bigint			bigint::operator>>(unsigned int toShift) const
{
	bigint	res = *this;
	if (toShift > res._digits.size())
	{
		res._digits = "0";
		return (res);
	}
	res._digits.erase(res._digits.begin(), res._digits.begin() + toShift);
	return (res);
}

bigint			&bigint::operator<<=(unsigned int toShift) 
{
	*this = *this << toShift;
	return (*this);
}

bigint			&bigint::operator>>=(unsigned int toShift)
{
	*this = *this >> toShift;
	return (*this);
}

bigint			&bigint::operator<<=(const bigint &toShift)
{
	unsigned int s = 0;
	for (int i = 0; i < toShift._digits.size(); i++)
		s = s * 10 + (toShift._digits[i] - '0');
	*this = *this << s;
	return (*this);
}
	
bigint			&bigint::operator>>=(const bigint &toShift)
{
	unsigned int s = 0;
	for (int i = 0; i < toShift._digits.size(); i++)
		s = s * 10 + (toShift._digits[i] - '0');
	*this = *this >> s;
	return (*this);
}

bigint			&bigint::operator++()
{
	*this += bigint(1);
	return (*this);
}

bigint			bigint::operator++(int) const
{
	bigint res = *this;
	res += bigint(1);
	return (res);
}

std::string		bigint::getDigits() const
{
	return (_digits);
}

std::ostream		&operator<<(std::ostream &out, const bigint &nbr)
{
	std::string str(nbr.getDigits());
	std::reverse(str.begin(), str.end());
	out << str;
	return (out);
}
