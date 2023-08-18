#include "Harl.hpp"

void Harl::complain(std::string level){
    std::string  str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

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
        debug();
        break;
    case 1:
        info();
        break;
    case 2:
        warning();
        break;
    case 3:
        error();
        break;
    default:
        std::cout << "[DEFAULT]\n" << "this is default message";
        break;
    }
}

void Harl::debug(void) {
    std::cout << "[-DEBUG-]" << std::endl;
    std::cout << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum. Gerçekten seviyorum!" << std::endl;
}

void Harl::info(void){
    std::cout << "[-INFO-]" << std::endl;
    std::cout << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını istemezdim!" << std::endl;
}

void Harl::warning(void){
    std::cout << "[-WARNING-]" << std::endl;
    std::cout << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum.  Ben yıllardır geliyorum, sen geçen aydan beri burada çalışmaya başladın." << std::endl;
}

void Harl::error(void){
    std::cout << "[-ERROR-]" << std::endl;
    std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << std::endl;
}