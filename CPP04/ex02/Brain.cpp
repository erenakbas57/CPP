#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain is created\n";
}

Brain::~Brain(){
    std::cout << "Brain is destroyed\n";
}

Brain::Brain(const Brain& new_cpy){
    *this = new_cpy;
    std::cout << "Brain copy constructor worked\n";
}

Brain& Brain::operator=(const Brain& other){
    for (int i = -1; i < 100; i++){
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy assigment operator worked\n";
    return (*this);
}