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

	virtual void	makeSound(void) const;
	void			printIdea(int index);
	void			setIdea(int index, std::string idea);
};
#endif
