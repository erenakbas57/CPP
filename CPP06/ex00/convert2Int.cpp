#include "ScalarConverter.hpp"

void ScalarConverter::convert2Int(std::string value)
{
    double d = std::atoi(value.c_str());
    if (d > MAX_INT || d < MIN_INT)
    {
        std::cout << "char  : impossible" << std::endl;
        std::cout << "int   : impossible" << std::endl;
        std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
        std::cout << "double: " << d <<  ".0" << std::endl;
    }
    else
    {
        if (d >= 32 && d <= 126)
            std::cout << "char  : '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char  : Non displayable" << std::endl;
        std::cout << "int   : " << static_cast<int>(d) << std::endl;
        if (d > MAX_FLOAT)
            std::cout << "float : inff" << std::endl;
        else if (d < MIN_FLOAT) 
            std::cout << "float : -inff" << std::endl;
        else
            std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    }

}