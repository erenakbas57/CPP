#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>

class Brain
{
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& new_cpy);
        Brain& operator=(const Brain& other);
};

#endif