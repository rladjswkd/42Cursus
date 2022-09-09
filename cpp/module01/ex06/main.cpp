/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:47:49 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:47:50 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
// c++ -Wall -Wextra -Werror flags causes an error for switch statement when some cases have no break statement. so switch is not suitable.
int	main(int argc, char **argv){
	Harl	harl;

	if (argc < 2)
		return (0);
	harl.complain(argv[1]);
	return (0);
}
