#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat		*wrongCatWrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();
	wrongCatWrongCat->makeSound();

	delete (meta);
	delete (i);
	delete (j);
	delete (wrongMeta);
	delete (wrongCat);
	delete (wrongCatWrongCat);
	return 0;
}