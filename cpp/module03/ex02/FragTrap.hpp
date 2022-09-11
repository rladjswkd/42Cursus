#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(FragTrap &);
	FragTrap(std::string);
	~FragTrap(void);
	FragTrap	&operator=(FragTrap &);
	void	highFivesGuys(void);
};
#endif