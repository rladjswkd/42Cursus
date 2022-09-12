/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:22:16 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:22:17 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>
class ClapTrap
{
private:
	std::string	name;
	int			hitPoint;
	int			energyPoint;
	int			attackDamage;

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
};
#endif
