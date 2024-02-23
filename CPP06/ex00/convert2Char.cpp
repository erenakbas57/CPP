#include "ScalarConverter.hpp"

void ScalarConverter::convert2Char(std::string value)
{
    char c = value[0];
    int i = static_cast<int>(c);
    if (i >= 32 && i <= 126)
        std::cout << "char  : '" << c << "'" << std::endl;
    else
        std::cout << "char  : Non displayable" << std::endl;
    std::cout << "int   : " << i << std::endl;
    std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}