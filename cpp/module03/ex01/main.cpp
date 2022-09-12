/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:22:40 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:22:41 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void){
	ClapTrap	ct1;
	ScavTrap	ct2("CT2");
	ScavTrap	ct3("CT3");

	std::cout << "Example message of ClapTrap class' attack : ";
	ct1.attack("nobody");
	
	std::cout << "CT3's hit point : " << ct3.getHitPoint() << std::endl;
	ct2.attack("CT3");
	ct3.takeDamage(ct2.getAttackDamage());
	std::cout << "CT3's hit point : " << ct3.getHitPoint() << std::endl;
	ct3.beRepaired(42);
	std::cout << "CT3's hit point : " << ct3.getHitPoint() << std::endl;
	
	ScavTrap	copiedCt3(ct3);
	std::cout << "CT3's name :  " << ct3.getName() << std::endl;
	std::cout << "CT3's hit point : " << ct3.getHitPoint() << std::endl;
	std::cout << "CT3's energy point : " << ct3.getEnergyPoint() << std::endl;
	std::cout << "CT3's attack damage : " << ct3.getAttackDamage() << std::endl;
	std::cout << "CT3's class name : " << ct3.getClassName() << std::endl;

	return (0);
}
