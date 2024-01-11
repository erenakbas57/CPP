#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
        Brain *think;
    public:
        Dog();
        ~Dog();
        Dog(const Dog& new_cpy);
        Dog& operator=(const Dog& other);
        void makeSound() const;
};



#endif