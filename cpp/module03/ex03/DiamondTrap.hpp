/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:22:56 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:22:57 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	name;
public:
	DiamondTrap(void);
	DiamondTrap(DiamondTrap &);
	DiamondTrap(std::string);
	~DiamondTrap(void);
	DiamondTrap	&operator=(DiamondTrap &);
	void	whoAmI(void);
	std::string	getPrivateName(void);
};
#endif
