#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character : public ICharacter
{
private:
	AMateria	*inventory[4];
public:
	Character(void);
	Character(Character &);
	~Character(void);
	Character	&operator=(Character &);

	std::string const & getName() const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};
#endif