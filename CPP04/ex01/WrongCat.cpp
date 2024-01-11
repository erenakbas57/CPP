#include "WrongCat.hpp"

WrongCat::WrongCat(){
    type = "WrongCat";
    std::cout << "WrongCat is created\n";
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat is destroyed\n";
}


WrongCat::WrongCat(const WrongCat& new_cpy){
    *this = new_cpy;
    std::cout << "WrongCat copy constructor worked\n";
}


WrongCat& WrongCat::operator=(const WrongCat& other){
    type = other.type;
    std::cout << "WrongCat copy assigment operator worked\n";
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "WRONG CAT : MEOWW    MEOWW    MEOWW\n";
}