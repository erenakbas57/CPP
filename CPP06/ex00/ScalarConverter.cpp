#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string value)
{
    int type = getTypes(value);
    if (type == IMPOSSIBLE)
    {
        std::cout << "char  : impossible" << std::endl;
        std::cout << "int   : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    else 
    {
        try
        {
            if (type == CHAR)
                convert2Char(value);
            else if (type == INT)
                convert2Int(value);
            else if (type == DOUBLE)
                convert2Double(value);
            else if (type == FLOAT)
                convert2Float(value);
            else if (type == NANF)
                convert2Nanf();
        }
        catch(const std::out_of_range& e)
        {
            std::cout << "char  : impossible" << std::endl;
            std::cout << "int   : impossible" << std::endl;
            std::cout << "float : impossible" << std::endl;
            if (value[0] == '-')
                std::cout << "double: -inf" << std::endl;
            else
                std::cout << "double: inf" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

int ScalarConverter::getTypes(std::string value)
{
    int len = value.length();
    int i = 0;
    int dot = 0;
    int f = 0;
    int sign = 0;

    int dot_i = 0;
    int f_i = 0;
    int sign_i = 0;
    if (len == 1)
    {
        if (value[0] >= '0' && value[0] <= '9')
            return (INT);
        else
            return (CHAR);
    }
    if (value == "nan" || value == "nanf")
        return (NANF);
    while (value[i])
    {
        if (!(value[i] >= '0' && value[i] <= '9') && value[i] != '.' && value[i] != 'f' && value[i] != '-')
            return (IMPOSSIBLE);
        if (value[i] == '.')
        {
            dot++;
            dot_i = i;
        }
        if (value[i] == 'f')
        {
            f++;
            f_i = i;
        }
        if (value[i] == '-')
        {
            sign++;
            sign_i = i;
        }
        i++;
    }
    if ((dot > 1) || (f > 1) || (sign > 1) || (dot == 1 && (dot_i == 0 || dot_i == (len - 1))) || (f == 1 && f_i != (len - 1)) || (sign == 1 && sign_i != 0))
        return (IMPOSSIBLE);
    if (dot == 0 && f == 0 && sign <= 1)
        return (INT);
    if (dot == 1 && f == 1 && sign <= 1)
        return (FLOAT);
    if (dot == 1 && f == 0 && sign <= 1)
        return (DOUBLE);
    return (IMPOSSIBLE);
}