#include "serialization.hpp"

int main()
{
    {
        int a = 42;
        int *ptr = &a;

        uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
        cout << "Address: " << addr << endl;
        int * value = reinterpret_cast<int *>(addr);
        cout << "Value: " << *value << endl;
    }
    cout << "--------------------------\n";
    {
        Data cigaratte("Marlboro", 50);
        cout << "Original address         : " << &cigaratte << endl;
        cout << "Original cigaratte       : " << cigaratte.getName() << endl;
        cout << "Original price           : " << cigaratte.getPrice() << endl;

        uintptr_t value = serialize(&cigaratte);
        cout << "Serialize edilmis adres : " << value << endl;
        char * addr = reinterpret_cast<char *>(value);
        int* pricePtr = reinterpret_cast<int*>(addr + sizeof(std::string));
        cout << "Serialize edilmis cigaratte : " << addr << endl;
        cout << "Serialize edilmis price : " << *pricePtr << endl;
        Data *cigaratte2 = deserialize(value);
        cout << "Deserialize edilmis deger: " << cigaratte2 << endl;
        cout << "Deserialize cigaratte    : " << cigaratte2->getName() << endl;
        cout << "Deserialize price        : " << cigaratte2->getPrice() << endl;
    }
}