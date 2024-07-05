#include "RPN.hpp"

int control(char **av)
{
    std::deque<char> infix;
    std::string str = av[1];

    int i = 0;
    if (strchr("0123456789", str[i]))
        infix.push_back(str[i]);
    else
    {
        std::cerr << "Error: first value is incorrect." << std::endl;
        return 1;
    }
    i++;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' && strchr(NUMBER, str[i + 1]))
            infix.push_back(str[i + 1]);
        else
        {
            std::cerr << "Error: Wrong usage." << std::endl;
            return 1;
        }
        i += 2;
    }
    int size = infix.size();
    if (!isdigit(infix[0]) || isdigit(infix[size - 1]))
    {
        std::cerr << "Error: first or last value is incorrect." << std::endl;
        return 1;
    }
    for (int i = 1; i < size;)
    {
        int operandCount = 0;
        int numberCount = 0;
        if (std::isdigit(infix[i]))
        {
            numberCount++;
            i++;
            while (i < size && std::isdigit(infix[i]))
            {
                numberCount++;
                i++;
            }
        }
        if (strchr("+-*/", infix[i]))
        {
            i++;
            operandCount++;
            while (i < size && std::strchr("+-*/", infix[i]))
            {
                operandCount++;
                i++;
            }
        }
        if (numberCount != operandCount)
        {
            std::cerr << "Error" << std::endl;
            return (1);
        }
    }
    return (0);
}

std::deque<char> fill(char *av)
{
    std::deque<char> infix;
    std::string str = av;
    int i = 0;
    while (str[i] != '\0')
    {
        if (strchr(NUMBER, str[i]))
            infix.push_back(str[i]);
        i++;
    }
    return infix;
}

void operation(char **av)
{
    std::deque<char> infix = fill(av[1]);
    std::deque<char>::iterator it = infix.begin();
    std::deque<std::string> rpn;

    for (; it != infix.end(); *it++)
    {
        rpn.push_back(std::string(1, *it));
        int size = rpn.size();
        if (size >= 3)
        {

            std::string op1 = rpn[size - 1];
            int op2 = atoi(rpn[size - 2].c_str());
            int op3 = atoi(rpn[size - 3].c_str());
            int result;
            if (op1 == "+")
            {
                result = op3 + op2;
                rpn.erase(rpn.end() - 3, rpn.end());
                rpn.push_back(std::to_string(result));
            }
            else if (op1 == "-")
            {
                result = op3 - op2;
                rpn.erase(rpn.end() - 3, rpn.end());
                rpn.push_back(std::to_string(result));
            }
            else if (op1 == "*")
            {
                result = op3 * op2;
                rpn.erase(rpn.end() - 3, rpn.end());
                rpn.push_back(std::to_string(result));
            }
            else if (op1 == "/")
            {
                if (op2 == 0)
                {
                    std::cout << "Error: division by zero error\n";
                    exit(-1);
                }
                result = op3 / op2;
                rpn.erase(rpn.end() - 3, rpn.end());
                rpn.push_back(std::to_string(result));
            }
        }
    }
    std::cout << rpn[0] << std::endl;
}