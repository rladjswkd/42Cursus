#include "ClapTrap.hpp"

int	main(void){
	ClapTrap	ct1;
	ClapTrap	ct2(ct1);
	ClapTrap	ct3("CT3");
	ClapTrap	ct4 = ct3;
	ClapTrap	ct5("CT5");

	ct1.attack("CT5");
	std::cout << "CT5's hit point : " << ct5.getHitPoint() << std::endl;
	ct5.takeDamage(ct1.getAttackDamage());
	std::cout << "CT5's hit point : " << ct5.getHitPoint() << std::endl;
	ct5.beRepaired(42);
	std::cout << "CT5's hit point : " << ct5.getHitPoint() << std::endl;
	return (0);
}