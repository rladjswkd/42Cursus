#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
class FragTrap : virtual public ClapTrap
{
private:
	const int	FTHitPoint;
	const int	FTAttackDamage;
public:
	FragTrap(void);
	FragTrap(FragTrap &);
	FragTrap(std::string);
	~FragTrap(void);
	FragTrap	&operator=(FragTrap &);
	void	highFivesGuys(void);
	int		getFTHitPoint(void);
	int		getFTAttackDamage(void);
};
#endif