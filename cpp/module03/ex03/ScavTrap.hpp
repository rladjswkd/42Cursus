/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:23:04 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:23:04 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap
{
private:
	const int	STEnergyPoint;
public:
	ScavTrap(void);
	ScavTrap(ScavTrap &);
	ScavTrap(std::string);
	~ScavTrap(void);
	ScavTrap	&operator=(ScavTrap &);
	void	attack(const std::string &);
	void	guardGate(void);
	int		getSTEnergyPoint(void);
};
#endif
