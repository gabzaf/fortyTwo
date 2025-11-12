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
    _digits = _digits.subtr(0, i + 1);
}

std::string Bigint::addStrings(const std::string &a, const std::string &b) const
{
    std::string res;
    //Init the carry var, used to pass a '1' to the next column/index.
    int         carry = 0;
    //Determine the len of the longer str, which sets the min nbr of loop iterations required.
    int         len   = std::max(a.size(), b.size());
    // Loop through the digits as long as there are still digits to process (i < len) 
    // OR a final carry value remains (carry is non-zero).
    for (int i = 0; i < len || carry; i++)
    {
        // Get the digit from string 'a' at index 'i'. 
        // If 'i' exceeds the length of 'a' (no more digits), use 0.
        // Subtracting '0' converts the character digit (e.g., '5') into its integer value (5).
        int digitA = i < (int) a.size() ? a[i] - '0' : 0;
        int digitB = i < (int) b.size() ? b[i] - '0' : 0;
        int sum    = digitA + digitB + carry;
        // Append the current column's final digit to the result string ('res').
        // 'sum % 10' gives the ones place (the digit to be written down).
        // Adding '+ '0'' converts the integer digit back into its character representation (e.g., 5 -> '5').
        res.push_back((sum % 10) + '0');
        // Calculate the new carry for the next column. 
        // 'sum / 10' gives the tens place (which is 0 or 1 for two-digit sums).
        carry = sum / 10;
    }
    return (res);
}

Bigint Bigint::operator+(const bigint &other) const
{
    Bigint res = *this;
    res._digits = addStrings(_digits, other._digits);
    res.removeZeros();
    return (res);
}

Bigint Bigint::operator+=(const Bigint &other)
{
    _digits = addStrings(_digits, other._digits);
    removeZeros();
    return (*this);
}