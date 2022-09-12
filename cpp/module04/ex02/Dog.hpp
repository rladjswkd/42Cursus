#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal
{
private:
	Brain	*brain;
public:
	Dog(void);
	Dog(Dog &);
	~Dog(void);
	Dog &operator=(Dog &);

	void	makeSound(void) const;
};
#endif
