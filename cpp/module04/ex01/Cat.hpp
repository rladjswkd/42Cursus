#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
private:
	Brain	*brain;
public:
	Cat(void);
	Cat(Cat &);
	~Cat(void);
	Cat &operator=(Cat &);

	virtual void	makeSound(void) const;
	void			printIdea(int);
};
#endif

