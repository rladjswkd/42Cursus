#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int	main(void){
	Intern	someRandomIntern;
	Form	*rrf;
	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
	
	Bureaucrat	b("Someone", 1);
	b.signForm(*rrf);
	b.executeForm(*rrf);
	return (0);
}