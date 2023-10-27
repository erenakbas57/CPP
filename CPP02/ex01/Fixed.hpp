#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <math.h>

class Fixed{
    private:
        int number;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(const Fixed& new_cpy);
        ~Fixed();
        Fixed& operator=(const Fixed& other);
        int toInt(void) const;
        float toFloat(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &obj, const Fixed& fix);

#endif