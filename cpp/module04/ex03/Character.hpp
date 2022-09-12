#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
class Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*slot[4];
public:
	Character(void);
	Character(Character &);
	Character(std::string);
	~Character(void);
	Character	&operator=(Character &);

	std::string const & getName() const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);

	AMateria	*getSlotItem(int);
};
#endif