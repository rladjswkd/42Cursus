/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:46:46 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:46:47 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_HPP
#define HARL_HPP
#include <string>

class Harl
{
private:
	void		(Harl::*fp[5])(void);
	std::string	funcNames[4];

	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);
	void		fail(void);
public:
				Harl(void);
	void		complain(std::string);
};
#endif
