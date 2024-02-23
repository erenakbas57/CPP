#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int ac, char *av[])
{
    
    if (ac != 2)
    {
        std::cout << "Usage: ./scalar [value]" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    
    
    return (0);
}