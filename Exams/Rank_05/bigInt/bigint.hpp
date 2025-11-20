#include <iostream>
#include <string>

class Bigint
{
    private:
        std::string _digits;

        std::string addStrings(const std::string &a, const std::string &b) const;
        void        removeZeros();
        void        isZero() const;
        bool        checkDigits(const std::string &s) const;

    public:
        Bigint();
        Bigint(unsigned int nbr);
        ~Bigint();

        Bigint operator+(const Bigint &other) const;
        Bigint operator+=(const Bigint &other);
        
        bool operator==(const Bigint &other) const;
        bool operator!=(const Bigint &other) const;
        bool operator<(const Bigint &other) const;
        bool operator>(const Bigint &other) const;
        bool operator<=(const Bigint &other) const;
        bool operator>=(const Bigint &other) const;

        Bigint operator<<(unsigned int toShift) const;
        Bigint operator>>(unsigned int toShift) const;
        Bigint &operator<<=(unsigned int toShift);
        Bigint &operator>>=(unsigned int toShift);

        Bigint &operator<<=(const Bigint &toShift);
        Bigint &operator>>=(const Bigint &toShift);
        
        Bigint &operator++();
        Bigint operator++(int);

        std::string getDigits() const;
};

std::ostream &operator<<(std::ostream &out, const Bigint &nbr);

