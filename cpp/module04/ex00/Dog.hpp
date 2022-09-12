#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
class Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog &);
	~Dog(void);
	Dog &operator=(Dog &);

	void	makeSound(void) const;
};
#endif
