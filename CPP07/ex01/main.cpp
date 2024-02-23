#include "iter.hpp"


int main()
{
    int int_array[] = {1, 2, 3, 4, 5};
    std::string string_array[] = {"Hello", "World", "!"};

    std::cout << "int_array:" << std::endl;
    iter(int_array, 5, print);
    std::cout << std::endl;

    std::cout << "string_array:" << std::endl;
    iter(string_array, 3, print);
    std::cout << std::endl;

    double double_array[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    std::cout << "double_array:" << std::endl;
    iter(double_array, 5, print);
    std::cout << std::endl;
    return 0;
}