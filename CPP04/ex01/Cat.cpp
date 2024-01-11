#include "Cat.hpp"

Cat::Cat(){
    type = "CAT";
    std::cout << "Cat is created\n";
    think = new Brain();
}

Cat::~Cat(){
    delete think;
    std::cout << "Cat is destroyed\n";
}


Cat::Cat(const Cat& new_cpy){
    *this = new_cpy;
    std::cout << "Cat copy constructor worked\n";
}


Cat& Cat::operator=(const Cat& other){
    type = other.type;
    think = other.think;
    std::cout << "Cat copy assigment operator worked\n";
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "CAT : MEOWW    MEOWW    MEOWW\n";
}