#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// Animal* animals[6];

	Animal* tmp = new Dog();
	delete tmp;

	// for (int i = 0; i < 3; ++i)
	// {
	// 	std::cout << "dog: " << i << std::endl;
	// 	animals[i] = new Dog();
	// }
	// for (int i = 3; i < 6; ++i)
	// {
	// 	std::cout << "cat: " << i << std::endl;
	// 	animals[i] = new Cat();
	// }
	// for (int i = 0; i < 6; ++i)
	// {
	// 	animals[i]->makeSound();
	// }
	// for (int i = 0; i < 6; ++i)
	// {
	// 	std::cout << "destruct: " << i << std::endl;
	// 	delete animals[i];
	// }
	return (0);
}