#include "Bureaucrat.hpp"

int	main(void){
	Bureaucrat	b1(0);
	Bureaucrat	b2(151);
	Bureaucrat	b3(50);
	Bureaucrat	b4(150);
	Bureaucrat	b5(1);

	b3.incGrade();
	// b3.decGrade();
	b4.decGrade();
	b5.incGrade();

	b3.setName("Bu");
	std::cout << b3 << std::endl;
	return (0);
}