#include "Identify.hpp"

int main()
{
    for (int i = 0; i < 8; i++)
    {
        Base *ptr;
        ptr = generate();
        identify(ptr);
        identify(*ptr);
        delete ptr;
    }
    return (0);
}