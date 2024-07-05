#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2){
        std::cerr << "Usage: " << av[0] << " \"<expression>\" " << std::endl;
        return 1;
    }
    if (control(av))
        return 1;
    operation(av);
    return 0;
}