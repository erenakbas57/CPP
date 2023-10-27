#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::Fixed(const int nbr) {
    std::cout << "Int constructor called" << std::endl;
    number = nbr * 256;
}

Fixed::Fixed(const float nbr) {
    std::cout << "Float constructor called" << std::endl;
    number = (int)roundf(nbr * 256);
}

Fixed::Fixed(const Fixed& new_cpy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = new_cpy;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->number = other.number;
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (number);
}

void Fixed::setRawBits(int const raw) {
    number = raw;
}

float Fixed::toFloat(void) const {
    return ((float)number / 256);
}

int Fixed::toInt(void) const {
    return (number >> bits);
}

std::ostream& operator<<(std::ostream& obj, const Fixed& fix)
{
	obj << fix.toFloat();
	return (obj);
}