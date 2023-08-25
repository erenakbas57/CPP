#include "Fixed.hpp"


Fixed::Fixed(){
    cout << "Default constructor called" << endl;
    number = 0;
}

Fixed::Fixed(const Fixed& new_cpy){
    cout << "Copy constructor called" << endl;
    number = new_cpy.getRawBits();
}

Fixed::~Fixed(){
    cout << "Destructor called" << endl;
}

Fixed& Fixed::operator=(const Fixed& other){
    cout << "Copy assignment operator called" << endl;
    this->number = other.number;
    return (*this);
}

int Fixed::getRawBits(void) const {
    cout << "getRawBits member function called" << endl;
    return (number);
}

void Fixed::setRawBits(int const raw){
    number = raw;
}