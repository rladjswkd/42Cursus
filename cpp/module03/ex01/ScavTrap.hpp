#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
class ScavTrap
{
private:
public:
	ScavTrap(void);
	ScavTrap(ScavTrap &);
	~ScavTrap(void);
	ScavTrap	&operator=(ScavTrap &);
};
#endif