#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& new_cpy);
        Animal& operator=(const Animal& other);
        virtual void makeSound() const;
        std::string getType() const;
};

#endif