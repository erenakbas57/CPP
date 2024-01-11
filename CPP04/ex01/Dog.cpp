#include "Dog.hpp"

Dog::Dog(){
    type = "DOG";
    std::cout << "Dog is created\n";
    think = new Brain();
}

Dog::~Dog(){
    std::cout << "Dog is destroyed\n";
    delete think;
}

Dog::Dog(const Dog& new_cpy){
    *this = new_cpy;
    std::cout << "Dog copy constructor worked\n";
}

Dog& Dog::operator=(const Dog& other){
    type = other.type;
    think = other.think;
    std::cout << "Dog copy assigment operator worked\n";
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "DOG : WOAFF    WOAFF    WOAFF\n";
}