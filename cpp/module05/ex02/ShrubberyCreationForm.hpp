#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <fstream>
class ShrubberyCreationForm : public Form
{
private:
	std::string		target;
	std::ofstream	file;
public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm &other);

	void	execute(Bureaucrat const & executor) const;
};

ShrubberyCreationForm::ShrubberyCreationForm(void) : target("Notarget"), Form(145, 137){
	file.open(target + "_shrubbery");
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other){

}

ShrubberyCreationForm::~ShrubberyCreationForm(void){

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &other){

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	try{
		checkCondition(executor);
		file
	} catch(std::exception &ex){
		throw ex;
	}

}
#endif