#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), target("NoTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) { *this = other; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &other){
	target = other.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	std::ofstream	file;

	try{
		checkCondition(executor);
	} catch (std::exception &ex) {
		throw ex;
	}
	file.open(target + "_shrubbery");
	if (!file.is_open())
		throw FileNotOpenException();
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
}