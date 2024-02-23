#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NANF,
    IMPOSSIBLE
};

#define PLUS 1
#define SAME 0

#define MIN_INT    -2147483648
#define MAX_INT     2147483647
#define MIN_FLOAT  -3.40282e+38
#define MAX_FLOAT   3.40282e+38
#define MIN_DOUBLE -1.79769e+308
#define MAX_DOUBLE  1.79769e+308

class ScalarConverter
{
    public:
        static void convert(std::string value);
        static int  getTypes(std::string value);

        static void convert2Char(std::string value);
        static void convert2Int(std::string value);
        static void convert2Float(std::string value);
        static void convert2Double(std::string value);
        static void convert2Nanf();
};

int decimal(std::string value);
int dec_control(std::string value);

#endif