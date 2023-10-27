#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    number = 0;
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
    this->number = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (number);
}

void Fixed::setRawBits(int const raw) {
    number = raw;
}