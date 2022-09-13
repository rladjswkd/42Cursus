#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
class Cat : public Animal
{
public:
	Cat(void);
	Cat(Cat &);
	~Cat(void);
	Cat &operator=(Cat &);

	virtual void	makeSound(void) const;
};
#endif

