#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
        Brain *think;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& new_cpy);
        Cat& operator=(const Cat& other);
        void makeSound() const;
};



#endif