#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p){
	if (dynamic_cast<A*>(p) != 0){
		std::cout << "Actual type : A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p) != 0){
		std::cout << "Actual type : B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p) != 0){
		std::cout << "Actual type : C" << std::endl;
		return ;
	}
}

void identify(Base& p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Actual type : A" << std::endl;
	} catch (std::exception &ex){
		try{
			(void)dynamic_cast<B&>(p);
			std::cout << "Actual type : B" << std::endl;
		} catch (std::exception &ex){
			try{
				(void)dynamic_cast<C&>(p);
				std::cout << "Actual type : C" << std::endl;
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