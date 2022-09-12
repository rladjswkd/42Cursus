#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(WrongCat &);
	~WrongCat(void);
	WrongCat &operator=(WrongCat &);

	void	makeSound(void) const;
};
#endif

