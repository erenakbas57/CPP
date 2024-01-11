#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


#include <iostream>
#include <typeinfo>
int main(){
{
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete	meta;
	delete	j;
	delete	i;
	std::cout << "\n----------------------------------\n\n";
}
{
	const WrongAnimal* meta = new WrongAnimal(); 
	const WrongAnimal* i = new WrongCat();
	i->makeSound();
	meta->makeSound();

	delete	meta;
	delete	i;
}
    return 0;
}