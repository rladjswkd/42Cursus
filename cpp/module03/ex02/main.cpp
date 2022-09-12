/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:22:50 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:22:51 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void){
	ClapTrap	ct1;
	FragTrap	ct2("CT2");
	FragTrap	ct3("CT3");

	std::cout << "Example message of ClapTrap class' attack : ";
	ct1.attack("nobody");
	
	std::cout << "CT3's hit point : " << ct3.getHitPoint() << std::endl;
	ct2.attack("CT3");
	ct3.takeDamage(ct2.getAttackDamage());
	std::cout << "CT3's hit point : " << ct3.getHitPoint() << std::endl;
	ct3.beRepaired(42);
	std::cout << "CT3's hit point : " << ct3.getHitPoint() << std::endl;
	
	FragTrap	copiedCt3(ct3);
	std::cout << "Copied CT3's name :  " << copiedCt3.getName() << std::endl;
	std::cout << "Copied CT3's hit point : " << copiedCt3.getHitPoint() << std::endl;
	std::cout << "Copied CT3's energy point : " << copiedCt3.getEnergyPoint() << std::endl;
	std::cout << "Copied CT3's attack damage : " << copiedCt3.getAttackDamage() << std::endl;
	std::cout << "Copied CT3's class name : " << copiedCt3.getClassName() << std::endl;
	ct3.highFivesGuys();
	return (0);
}
