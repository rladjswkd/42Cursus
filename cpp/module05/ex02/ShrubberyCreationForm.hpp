#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <fstream>
class ShrubberyCreationForm : public Form
{
private:
	std::string		target;
public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm &other);

	void	execute(Bureaucrat const & executor) const;
};

ShrubberyCreationForm::ShrubberyCreationForm(void): target("Notarget"), Form(145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other){

}

ShrubberyCreationForm::~ShrubberyCreationForm(void){

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &other){

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::ofstream	file;

	try{
		file.open(target + "_shrubbery");
		checkCondition(executor);
		file << "                                                      .\n"
			    "                                              .         ;\n"
			    "                 .              .              ;%     ;;\n"
				"                   ,           ,                :;%  %;\n"
				"                    :         ;                   :;%;'     .,\n"
				"           ,.        %;     %;            ;        %;'    ,;\n"
				"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
				"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
				"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
				"                `%;.     ;%;     %;'         `;%%;.%;'\n"
				"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
				"                    `:%;.  :;bd%;          %;@%;'\n"
				"                      `@%:.  :;%.         ;@@%;'\n"
				"                        `@%.  `;@%.      ;@@%;\n"
				"                          `@%%. `@%%    ;@@%;\n"
				"                              %@bd%%%bd%%:;\n"
				"                                #@%%%%%:;;\n"
				"                                %@@%%%::;\n"
				"                                %@@@%(o);  . '\n"
				"                                %@@@o%;:(.,'\n"
				"                            `.. %@@@o%::;\n"
				"                               `)@@@o%::;\n"
				"                                %@@(o)::;\n"
				"                               .%@@@@%::;\n"
				"                               ;%@@@@%::;.\n"
				"                              ;%@@@@%%:;;;.\n"
				"                          ...;%@@@@@%%:;;;;,..\n"
			 << std::endl;
		file.close();
	} catch(std::exception &ex){
		file.close();
		throw ex;
	}

}
#endif