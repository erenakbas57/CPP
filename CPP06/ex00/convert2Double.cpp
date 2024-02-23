#include "ScalarConverter.hpp"

void ScalarConverter::convert2Double(std::string value)
{
    double d = std::stod(value);
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
        if ((d > -100000.0 && d < 100000.0))
        {
            int dec = decimal(value);
            if (dec == 0)
            {
                std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
                std::cout << "double: " << d << ".0" << std::endl;
            }
            else
            {
                int control = dec_control(value);
                if (control)
                {
                    std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
                    std::cout << "double: " << d << ".0" << std::endl;
                }
                else
                {
                    std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
                    std::cout << "double: " << d << std::endl;
                }
            }
        }
        else
        {
            std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
            std::cout << "double: " << d << ".0" << std::endl;
        }
    }
}

int decimal(std::string value)
{
    double d = std::stod(value);
    if (!(d > -100000.0 && d < 100000.0))
        return (0);
    int i = 0;
    int number = 0;
    while (value[i])
    {
        if (value[i] >= '0' && value[i] <= '9')
            number++;
        if (value[i] == '.')
            break;
        i++;
    }
    i++;
    int j = 0;
    int max = (6 - number);
    while (value[i] && j < max)
    {
        if (value[i] >= '1' && value[i] <= '9')
            return (1);
        i++;
        j++;
    }
    return (0);
}

int dec_control(std::string value)
{
    double d = std::stod(value);
    int i = 0;
    int full = 0;
    int dec = 0;
    while (value[i])
    {
        if (value[i] >= '0' && value[i] <= '9')
            full++;
        if (value[i] == '.')
            break;
        i++;
    }
    i++;
    while (value[i])
    {
        if (value[i] == '9')
            dec++;
        if (value[i] != '9')
            break;
        i++;
    }
    int max = full + dec;
    if (max == 6)
    {
        if ((value[i] > '5' && value[i] <= '9') && d >= 4)
            return (PLUS);
        if ((value[i] >= '5' && value[i] <= '9'))
            i++;
        if (value[i] && (value[i] >= '2' && value[i] <= '9') && d < 4)
            return (PLUS);
    }
    return (SAME);
}