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

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->number = other.number;
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
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



bool Fixed::operator>(const Fixed& other) const{
	return (this->number > other.number);
}

bool Fixed::operator<(const Fixed& other) const{
	return (this->number < other.number);
}

bool Fixed::operator>=(const Fixed& other) const{
	return (this->number >= other.number);
}

bool Fixed::operator<=(const Fixed& other) const{
	return (this->number <= other.number);
}

bool Fixed::operator==(const Fixed& other) const{
	return (this->number == other.number);
}

bool Fixed::operator!=(const Fixed& other) const{
	return (this->number != other.number);
}



Fixed Fixed::operator+(const Fixed &other){
    Fixed ret;

    ret.setRawBits(this->number + other.number);
    return (ret);
}

Fixed Fixed::operator-(const Fixed &other){
    Fixed ret;

    ret.setRawBits(this->number - other.number);
    return (ret);
}

Fixed Fixed::operator*(const Fixed &other){
    Fixed ret;

    ret.setRawBits(this->number * other.number / 256);
    return (ret);
}

Fixed Fixed::operator/(const Fixed &other){
    Fixed ret;

    ret.setRawBits(this->number * 256 / other.number);
    return (ret);
}



Fixed& Fixed::operator++(void){
    number++;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed res = *this;
    this->number++;
    return (res);
}

Fixed& Fixed::operator--(void){
    number--;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed res = *this;
    this->number--;
    return (res);
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    if (a.number < b.number)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if ( a < b )
		return ( a );
	return ( b );
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
    if (a.number > b.number)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    if (a > b)
        return (a);
    else
        return (b);
}

std::ostream& operator<<(std::ostream& other, const Fixed& fixed)
{
	other << fixed.toFloat();
	return (other);
}