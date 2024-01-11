#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    type = "WrongAnimal";
    std::cout << "WrongAnimal is created\n";
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal is destroyed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& new_cpy){
    *this = new_cpy;
    std::cout << "WrongAnimal copy constructor worked\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    type = other.type;
    std::cout << "WrongAnimal copy assigment operator worked\n";
    return (*this);
}

void WrongAnimal::makeSound() const{
    std::cout << "WRONG ANIMAL : NO VOICE\n";
}

std::string WrongAnimal::getType() const{
    return (type);
}