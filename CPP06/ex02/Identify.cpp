#include "Identify.hpp"

A::A()
{
    std::cout << "A is created\n";
}

B::B()
{
    std::cout << "B is created\n";
}

C::C()
{
    std::cout << "C is created\n";
}

Base *generate(void) 
{
    int value = (std::rand() % 3) + 1;
    Base *ptr;
    if (value == 1)
        ptr = new A();
    else if (value == 2)
        ptr = new B();
    else if (value == 3)
        ptr = new C();
    else
    {
        ptr = NULL;
        std::cout << "Error" << std::endl;
    }
    return (ptr);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}