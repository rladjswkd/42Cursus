#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(ScavTrap &);
	ScavTrap(std::string);
	~ScavTrap(void);
	ScavTrap	&operator=(ScavTrap &);
	void	attack(const std::string &);
	void	guardGate(void);
};
#endif