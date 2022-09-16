#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>
class Brain
{
private:
	std::string	ideas[100];
public:
	Brain(void);
	Brain(Brain &);
	~Brain(void);
	Brain	&operator=(Brain &);

	std::string	getIdea(int index);
	void		setIdea(int index, std::string idea);
};
#endif