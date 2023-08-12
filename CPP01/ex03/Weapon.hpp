#include <iostream>


class Weapon{
    private:
        std::string type;
    public:
        Weapon(std::string gun) {type = gun;}
        const std::string& getType();
        void    setType(std::string str);
};