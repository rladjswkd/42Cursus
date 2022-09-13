/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:23:05 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:23:06 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void){
	DiamondTrap	dt1("DT1");
	DiamondTrap	dt2("DT2");
	DiamondTrap dt3;

	std::cout << std::endl;
	dt1.attack("DT2");
	dt2.takeDamage(dt2.getAttackDamage());
	dt2.beRepaired(42);
	std::cout << std::endl;
	std::cout << "DT2's name :  " << dt2.getName() << std::endl;
	std::cout << "DT2's hit point : " << dt2.getHitPoint() << std::endl;
	std::cout << "DT2's energy point : " << dt2.getEnergyPoint() << std::endl;
	std::cout << "DT2's attack damage : " << dt2.getAttackDamage() << std::endl;
	std::cout << "DT2's class name : " << dt2.getClassName() << std::endl;
	DiamondTrap	copiedDt2(dt2);
	std::cout << "Copied DT2's name :  " << copiedDt2.getName() << std::endl;
	std::cout << "Copied DT2's hit point : " << copiedDt2.getHitPoint() << std::endl;
	std::cout << "Copied DT2's energy point : " << copiedDt2.getEnergyPoint() << std::endl;
	std::cout << "Copied DT2's attack damage : " << copiedDt2.getAttackDamage() << std::endl;
	std::cout << "Copied DT2's class name : " << copiedDt2.getClassName() << std::endl;

	dt2.attack("ABC");
	copiedDt2.attack("ABC");
	dt3.attack("ABC");

	dt2.whoAmI();
	copiedDt2.whoAmI();

	dt2.guardGate();
	dt2.highFivesGuys();
	return (0);
}
