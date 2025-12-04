#include "bigint.hpp"

Bigint::Bigint() : _digits("0"){std::cout << "Constructor ready" << std::endl;}

Bigint::Bigint(unsigned int nbr)
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

Bigint::Bigint(const std::string& nbr)
{
    if(!checkDigits(nbr))
        _digits = "0";
    else
    {
        _digits = nbr;
        std::reverse(_digits.begin(), _digits.end());
        removeZeros();
    }
}

Bigint::~Bigint(){}

bool Bigint::checkDigits(const std::string &s) const
{
    if (s.empty())
        return (false);
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (!isdigit(s[i]))
            return (false);
    }
    return (true);
}

bool Bigint::isZero() const
{
    return (_digits == "0");
}

void Bigint::removeZeros()
{
    if (_digits.empty())
    {
        _digits = "0";
        return ;
    }
    int i = _digits.size() - 1;
    while (i > 1 && _digits[i] == '0')
        i--;
    _digits = _digits.substr(0, i + 1);
}

std::string Bigint::addStrings(const std::string &a, const std::string &b) const
{
    std::string res;
    int         carry = 0;
    int         len   = std::max(a.size(), b.size());
    for (int i = 0; i < len || carry; i++)
    {
        int digitA = i < (int) a.size() ? a[i] - '0' : 0;
        int digitB = i < (int) b.size() ? b[i] - '0' : 0;
        int sum    = digitA + digitB + carry;
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    return (res);
}

Bigint Bigint::operator+(const Bigint &other) const
{
    Bigint res = *this;
    res._digits = addStrings(_digits, other._digits);
    res.removeZeros();
    return (res);
}

Bigint &Bigint::operator+=(const Bigint &other)
{
    _digits = addStrings(_digits, other._digits);
    removeZeros();
    return (*this);
}

bool Bigint::operator==(const Bigint &other) const
{
    Bigint a = *this, b = other;
    a.removeZeros();
    b.removeZeros();
    return (a._digits == b._digits);
}

bool Bigint::operator!=(const Bigint &other) const
{
    return !(*this == other);
}

bool Bigint::operator<(const Bigint &other) const
{
    Bigint a = *this, b = other;
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

bool Bigint::operator>(const Bigint &other) const
{
    return (other < *this);
}

bool Bigint::operator<=(const Bigint &other) const
{
    return !(*this > other);
}

bool Bigint::operator>=(const Bigint &other) const
{
    return !(*this < other);
}

Bigint Bigint::operator<<(unsigned int toShift) const
{
    if (isZero() || toShift == 0)
        return (*this);
    Bigint res = *this;
    res._digits.insert(res._digits.begin(), toShift, '0');
    res.removeZeros();
    return (res);
}

Bigint Bigint::operator>>(unsigned int toShift) const
{
    if (isZero() || toShift == 0)
        return (*this);
    Bigint res = *this;
    if (res._digits.size() <= toShift)
        res._digits = "0";
    else
        res._digits.erase(res._digits.begin(), res._digits.begin() + toShift);
    res.removeZeros();
    return (res);
}

Bigint &Bigint::operator<<=(unsigned int toShift)
{
    *this = *this << toShift;
    return (*this);
}

Bigint &Bigint::operator>>=(unsigned int toShift) 
{
    *this = *this >> toShift;
    return (*this);
}

Bigint &Bigint::operator<<=(const Bigint &toShift)
{
    std::string str = toShift.getDigits();
    std::reverse(str.begin(), str.end());

    if (!checkDigits(str))
        return (*this);
    unsigned int s = 0;
    for (int i = 0; i < (int) str.size(); i++)
        s = s * 10 + (str[i] - '0');
    *this = *this << s;
    return (*this);
}

Bigint &Bigint::operator>>=(const Bigint &toShift)
{
    std::string str = toShift.getDigits();
    std::reverse(str.begin(), str.end());
    if (!checkDigits(str))
        return (*this);
    unsigned int s = 0;
    for (int i = 0; i < (int) str.size(); i++)
        s = s * 10 + (str[i] - '0');
    *this = *this >> s;
    return (*this);
}

Bigint &Bigint::operator++()
{
    *this += Bigint(1);
    return (*this);
}

Bigint Bigint::operator++(int)
{
    Bigint res = *this;
    *this += Bigint(1);
    return (res);
}

std::string Bigint::getDigits() const
{
    return (_digits);
}

std::ostream &operator<<(std::ostream &out, const Bigint &nbr)
{
    std::string str(nbr.getDigits());
    std::reverse(str.begin(), str.end());
    out << str;
    return (out);
}
