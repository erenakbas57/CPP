#include "Dog.hpp"

Dog::Dog(){
    type = "DOG";
    std::cout << "Dog is created\n";
}

Dog::~Dog(){
    std::cout << "Dog is destroyed\n";
}

Dog::Dog(const Dog& new_cpy){
    *this = new_cpy;
    std::cout << "Dog copy constructor worked\n";
}

Dog& Dog::operator=(const Dog& other){
    type = other.type;
    std::cout << "Dog copy assigment operator worked\n";
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "DOG : WOAFF    WOAFF    WOAFF\n";
}