#include <iostream>
#include <string>

class Bigint
{
    private:
        std::string _digits;

        std::string addStrings(const std::string &a, const std::string &b) const;
        void        removeZeros();

    public:
        Bigint();
        Bigint(unsigned int nbr);
        ~Bigint();

        Bigint operator+(const bigint &other) const;

}

