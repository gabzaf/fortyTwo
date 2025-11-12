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
        std::ostringstream oss;
        oss << nbr;
        _digits = oss.str();
        // **Reversing the digits:** The number is stored in reverse order
        // (e.g., 456 becomes "654"). This is done so the least significant 
        // digit (the 'ones' place) is at index 0, making subsequent arithmetic 
        // operations (like addition) more efficient, as they naturally start 
        // from the least significant digit.
        std::reverse(_digits.begin(), _digits.end());
    }
}

Bigint::~Bigint(){}

std::string Bigint::addStrings(const std::string &a, const std::string &b) const
{
    std::string res;
    int         carry = 0;
    int         len   = std::max(a.size(), b.size());

    
}

Bigint Bigint::operator+(const bigint &other) const
{
    Bigint res = *this;
    res.digits = addStrings(_digits, other._digits);
    res.removeZeros();
    return (res);
}