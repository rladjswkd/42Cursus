/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:34:32 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:34:33 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p){
	if (dynamic_cast<A*>(p) != 0){
		std::cout << "Actual type of the object of this pointer: A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) != 0){
		std::cout << "Actual type of the object of this pointer: B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) != 0){
		std::cout << "Actual type of the object of this pointer: C" << std::endl;
		return ;
	}
}

void identify(Base& p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Actual type of this reference: A" << std::endl;
	} catch (std::exception &ex){
		try{
			(void)dynamic_cast<B&>(p);
			std::cout << "Actual type of this reference: B" << std::endl;
		} catch (std::exception &ex){
			try{
				(void)dynamic_cast<C&>(p);
				std::cout << "Actual type of this reference: C" << std::endl;
			} catch (std::exception &ex){
				std::cout << "Wrong object!" << std::endl;
			}
		}
	}
}

Base	*generate(void){
	int	val;

	srand(time(NULL));
	val = rand() % 3;
	if (val == 0)
		return (new A);
	else if (val == 1)
		return (new B);
	else
		return (new C);
}

int	main(void){
	Base	*p = generate();

	identify(p);
	identify(*p);
	return (0);
}
