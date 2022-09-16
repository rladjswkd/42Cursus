#ifndef INTERN_HPP
#define INTERN_HPP
class Intern 
{
private:

public:

	Intern(void);
	Intern(Intern &);
	~Intern(void);
	Intern	&operator=(Intern &);
};

Intern::Intern(void){

}

Intern::Intern(Intern &){

}

Intern::~Intern(void){

}

Intern	&Intern::operator=(Intern &){

}
#endif