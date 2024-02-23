#include "ScalarConverter.hpp"

#include "ScalarConverter.hpp"

void ScalarConverter::convert2Float(std::string value)
{
    float d = std::stof(value);
    if (d > MAX_FLOAT || d < MIN_FLOAT)
    {
        std::cout << "char  : impossible" << std::endl;
        std::cout << "int   : impossible" << std::endl;
        if (d < MIN_FLOAT)
            std::cout << "float : -inff" << std::endl;
        else
            std::cout << "float : inff" << std::endl;
        std::cout << "double: " << d <<  ".0" << std::endl;
    }
    else if (d > MAX_INT || d < MIN_INT)
    {
        std::cout << "char  : impossible" << std::endl;
        std::cout << "int   : impossible" << std::endl;
        std::cout << "float : " << d << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(d) <<  ".0" << std::endl;
    }
    else
    {
        if (d >= 32 && d <= 126)
            std::cout << "char  : '" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "char  : Non displayable" << std::endl;
        std::cout << "int   : " << static_cast<int>(d) << std::endl;
        if ((d > -100000.0 && d < 100000.0))
        {
            int dec = decimal(value);
            if (dec == 0)
            {
                std::cout << "float : " << d << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
            }
            else
            {
                std::cout << "float : " << d << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(d) << std::endl;
            }
        }
        else
        {
            std::cout << "float : " << d << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
        }
    }
}