/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:45:03 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/10 03:45:04 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define	COUNT	42

Zombie	*zombieHorde(int N, std::string name);

int main(void){
    Zombie	*horde = zombieHorde(COUNT, "HEAP");

	for (int i = 0; i < COUNT; i++)
		horde->announce();
	delete[] (horde);
}
