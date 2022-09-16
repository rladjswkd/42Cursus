#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void){

	Form		*shrub = new ShrubberyCreationForm("myfile");
	Bureaucrat	b1("The target", 1);
	Bureaucrat	b2("Harry", 140);

	b1.executeForm(*shrub);
	b1.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << b1 << std::endl;
	b2.executeForm(*shrub);
	delete shrub;


	Form		*robotomy = new RobotomyRequestForm("The target");
	Bureaucrat	b3("Harry2", 1);

	b3.executeForm(*robotomy);
	b3.signForm(*robotomy);
	b3.executeForm(*robotomy);
	b3.executeForm(*robotomy);
	b3.executeForm(*robotomy);
	b3.executeForm(*robotomy);
	delete robotomy;


	Form		*presidential = new PresidentialPardonForm("The target");
	Bureaucrat	b4("Harry3", 6);

	b4.executeForm(*presidential);
	b4.signForm(*presidential);
	b4.executeForm(*presidential);
	b4.incGrade();
	b4.executeForm(*presidential);
	delete presidential;

	return (0);
	return (0);
}