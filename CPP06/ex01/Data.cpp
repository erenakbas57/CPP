#include "serialization.hpp"

Data::Data() : _name("Milk"),_price(20) {};

Data::Data(string name, int price) : _name(name), _price(price) {};

Data::Data(Data &other) : _name(other._name), _price(other._price) {};

Data &Data::operator=(Data &other) {    return (other); }

Data::~Data() {};

string Data::getName() const { return (_name); }

int Data::getPrice() const { return (_price); }

