#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name;
public:
	using FragTrap::hitPoint;
	using ScavTrap::energyPoint;
	using FragTrap::attackDamage;
	using ScavTrap::attack;
	DiamondTrap(void);
	DiamondTrap(DiamondTrap &);
	DiamondTrap(std::string);
	~DiamondTrap(void);
	DiamondTrap	&operator=(DiamondTrap &);
	void	whoAmI(void);
	std::string	getPrivateName(void);
};
#endif