#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>
class ClapTrap
{
protected:
	std::string	name;
	int			hitPoint;
	int			energyPoint;
	int			attackDamage;
	std::string	className;

public:
	ClapTrap(void);
	ClapTrap(ClapTrap &);
	ClapTrap(std::string);
	~ClapTrap(void);
	
	ClapTrap	&operator=(ClapTrap &);

	void	attack(const std::string&);
	void	takeDamage(unsigned int);
	void	beRepaired(unsigned int);

	std::string	getName(void);
	int			getHitPoint(void);
	int			getEnergyPoint(void);
	int			getAttackDamage(void);
	std::string	getClassName(void);
};
#endif