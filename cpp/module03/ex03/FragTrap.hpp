/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:22:58 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:22:59 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
