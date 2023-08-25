#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
using std::cout;
using std::string;
using std::endl;

class Fixed{
    private:
        int number;
        static const int bits;
    public:
        Fixed();
        Fixed(const Fixed& new_cpy);
        ~Fixed();
        Fixed& operator=(const Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif