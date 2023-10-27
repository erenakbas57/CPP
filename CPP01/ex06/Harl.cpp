#include "Harl.hpp"

void Harl::complain(std::string level){
    std::string  str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*choose[4])() = {
        choose[0] = &Harl::debug,
        choose[1] = &Harl::info,
        choose[2] = &Harl::warning,
        choose[3] = &Harl::error
    };
    int i = 0;
    while (i < 4)
    {
        if (level == str[i])
            break;
        i++;
    }
    
    switch (i)
    {
    case 0:
        (this->*choose[0])();
    case 1:
        (this->*choose[1])();
    case 2:
        (this->*choose[2])();
    case 3:
        (this->*choose[3])();
        break;
    default:
        std::cout << "[-DEFAULT-]\n" << "this is default message.\n";
        break;
    }
}

void Harl::debug(void) {
    std::cout << "[-DEBUG-]\n";
    std::cout << "Among many encrypted realities, I am here soon to be decoded.\n\n";
}

void Harl::info(void){
    std::cout << "[-INFO-]\n";
    std::cout << "Could everything be a simulation? I continue to explore the unknown world.\n\n";
}

void Harl::warning(void){
    std::cout << "[-WARNING-]\n";
    std::cout << "When reality is pushed to its limits, be careful. Something could go wrong!\n\n";
}

void Harl::error(void){
    std::cout << "[-ERROR-]\n";
    std::cout << "Something went wrong. Contact the system operator now!\n\n";
}