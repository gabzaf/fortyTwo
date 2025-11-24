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
		std::stringstream ss;
		ss << nbr;
		_digits = ss.str();
		std::reverse(_digits.begin(), _digits.end());
	}
}
bigint::bigint(const std::string &str)
{
	if (!checkDigits(str))
		_digits = "0";
	else
	{
		_digits = str;
		std::reverse(_digits.begin(), _digits.end());
		removeZeros();
	}
}

bigint::~bigint(){};

bool		bigint::checkDigits(const std::string &str) const
{
	if (str.empty())
		return (false);
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (!isdigit(str[i]))
				return (false);
	}
	return (true);
}

bool		bigint::isZero() const
{
	return (_digits == "0");
}

void		bigint::removeZeros()
{
	if (_digits.empty())
	{
		_digits = "0";
		return ;
	}
	int i = _digits.size() - 1;
	while (i > 1 && _digits[i] == '0')
		i--;
	_digits = _digits.substr(0, i+1);
}

std::string	bigint::addStrings(const std::string &a, const std::string &b) const
{
	std::string	res;
	int		carry = 0;
	int		len = std::max(a.size(), b.size());

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

bigint		bigint::operator+(const bigint &other) const
{
	bigint res = *this;
	res._digits = addStrings(_digits, other._digits);
	res.removeZeros();
	return (res);
}

bigint		&bigint::operator+=(const bigint &other)
{
	_digits = addStrings(_digits, other._digits);
	removeZeros();
	return (*this);
}

bool		bigint::operator==(const bigint &other) const
{
	bigint a = *this, b = other;
	
	a.removeZeros();
	b.removeZeros();
	return (a._digits == b._digits);
}

bool		bigint::operator!=(const bigint &other) const
{
	return (!(*this == other));
}

bool		bigint::operator<(const bigint &other) const
{
	bigint a = *this, b = other;

	a.removeZeros();
	b.removeZeros();
	if (a._digits.size() != b._digits.size())
		return (a._digits.size() < b._digits.size());
	for (int i = a._digits.size() - 1; i >= 0; i--)
	{
		if (a._digits[i] != b._digits[i])
			return (a._digits[i] < b._digits[i]);
	}
	return (false);
}

bool		bigint::operator>(const bigint &other) const
{
	return (other < *this);
}

bool		bigint::operator<=(const bigint &other) const
{
	return (!(*this > other));
}

bool		bigint::operator>=(const bigint &other) const
{
	return (!(*this < other));
}

bigint		bigint::operator<<(unsigned int toShift) const
{
	if (isZero() || toShift == 0)
		return (*this);
	bigint res = *this;
	res._digits.insert(res._digits.begin(), toShift, '0');
	res.removeZeros();
	return (res);
}

bigint		bigint::operator>>(unsigned int toShift) const
{
	if (isZero() || toShift == 0)
		return (*this);
	bigint res = *this;
	if (res._digits.size() <= toShift)
		res._digits = "0";
	else
		res._digits.erase(res._digits.begin(), res._digits.begin() + toShift);
	res.removeZeros();
	return (res);	
}

bigint		&bigint::operator<<=(unsigned int toShift)
{
	*this = *this << toShift;
	return (*this);
}

bigint		&bigint::operator>>=(unsigned int toShift)
{
	*this = *this >> toShift;
	return (*this);
}

bigint		&bigint::operator<<=(const bigint &toShift)
{
	std::string str = toShift._digits;
	std::reverse(str.begin(), str.end());
	if (!checkDigits(str))
		return (*this);
	unsigned int s = 0;
	for (int i = 0; i < (int)str.size(); i++)
		s = s * 10 + str[i] - '0';
	*this = *this << s;
	return (*this);
}

bigint		&bigint::operator>>=(const bigint &toShift)
{
	std::string str = toShift.getDigits();
	std::reverse(str.begin(), str.end());
	if (!checkDigits(str))
		return (*this);
	unsigned int s = 0;
	for (int i = 0; i < (int)str.size(); i++)
		s = s * 10 + str[i] - '0';
	*this = *this >> s;
	return (*this);
}

bigint		&bigint::operator++()
{
	*this += bigint(1);
	return (*this);
}

bigint		bigint::operator++(int)
{
	bigint res = *this;
	*this += bigint(1);
	return (res);
}

std::ostream	&operator<<(std::ostream &out, const bigint &nbr)
{
	std::string str(nbr.getDigits());
	std::reverse(str.begin(), str.end());
	out << str;
	return (out);
}

std::string bigint::getDigits() const
{
    return (_digits);
}







