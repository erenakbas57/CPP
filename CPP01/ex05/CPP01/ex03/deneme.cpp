#include <iostream>
using namespace std;


class Weapon{
    private:
        string gun;
    public:
        void set_gun(string name) {gun = name;}
        string get_gun() {return (gun);}
};

class   People1{
    private:
        string name;
        Weapon &gun;

    public:
        People1(string str, Weapon &wp) : name(str), gun(wp) {}
        void attack() {
            cout << name << " attacks with " << gun.get_gun() << endl;
        }
        void address(){
            cout << "People1 gun address: " << gun.get_gun() << endl;
        }
};


class   People2{
    private:
        string name;
        Weapon *gun;

    public:
        People2(string str, Weapon *wp)
        {
            name = str;
            gun = wp;
        }
        void attack() {
            cout << name << " attacks with " << gun->get_gun() << endl;
        }
        void address(){
            cout << "People2 gun address: " << gun->get_gun() << endl;
        }
};

class   People3{
    private:
        string name;
        Weapon gun;

    public:
        People3(string str, Weapon wp)
        {
            name = str;
            gun = wp;
        }
        void attack() {
            cout << name << " attacks with " << gun.get_gun() << endl;
        }
        void address(){
            cout << "People2 gun address: " << gun.get_gun() << endl;
        }
};
int main()
{
    Weapon knife;
    Weapon *sword;
    knife.set_gun("knife");
    sword->set_gun("sword");
    People1 eren("eren", knife);
    People2 ahmet("ahmet", sword);
    cout << "knife değişken adresi: " << &knife << endl;
    eren.address();
    ahmet.address();
    delete &eren;
    delete &ahmet;
 
}

