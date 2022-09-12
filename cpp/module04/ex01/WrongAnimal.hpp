#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
#include <iostream>
class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal &);
	~WrongAnimal(void);
	WrongAnimal &operator=(WrongAnimal &);

	void	makeSound(void) const;
	std::string	getType(void) const;
};
#endif
