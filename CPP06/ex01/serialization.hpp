#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
using namespace std;



class Data
{
    private:
        string  _name;
        int     _price;
    
    public:
        Data();
        Data(string name, int price);
        Data(Data &other);
        Data &operator=(Data &other);
        ~Data();

        string getName() const;
        int getPrice() const;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif