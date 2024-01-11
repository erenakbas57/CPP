#include "Animal.hpp"

Animal::Animal(){
    type = "Animal";
    std::cout << "Animal is created\n";
}

Animal::~Animal(){
    std::cout << "Animal is destroyed\n";
}

Animal::Animal(const Animal& new_cpy){
    *this = new_cpy;
    std::cout << "Animal copy constructor worked\n";
}

Animal& Animal::operator=(const Animal& other){
    type = other.type;
    std::cout << "Animal copy assigment operator worked\n";
    return (*this);
}

void Animal::makeSound() const{
    std::cout << "ANIMAL : NO VOICE\n";
}

std::string Animal::getType() const{
    return (type);
}