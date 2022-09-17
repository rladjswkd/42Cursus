#include <iostream>
#include <exception>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p){
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(p);
	if (a != 0){
		std::cout << "Actual type : A" << std::endl;
		return ;
	}
	b = dynamic_cast<B*>(p);
	if (b != 0){
		std::cout << "Actual type : B" << std::endl;
		return ;
	}
	c = dynamic_cast<C*>(p);
	if (c != 0){
		std::cout << "Actual type : C" << std::endl;
		return ;
	}
}

void identify(Base& p){
	try  {
		A	&a = dynamic_cast<A&>(p);
	} catch (std::exception &ex) {

	}
	B	&b;
	C	&c;


}
