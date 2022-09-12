/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 01:22:45 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/12 01:22:46 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
