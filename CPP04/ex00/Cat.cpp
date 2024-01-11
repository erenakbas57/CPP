#include "Cat.hpp"

Cat::Cat(){
    type = "CAT";
    std::cout << "Cat is created\n";
}

Cat::~Cat(){
    std::cout << "Cat is destroyed\n";
}


Cat::Cat(const Cat& new_cpy){
    *this = new_cpy;
    std::cout << "Cat copy constructor worked\n";
}


Cat& Cat::operator=(const Cat& other){
    type = other.type;
    std::cout << "Cat copy assigment operator worked\n";
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "CAT : MEOWW    MEOWW    MEOWW\n";
}