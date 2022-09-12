#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
private:
	AMateria	*learned[4];
public:
	MateriaSource(void);
	MateriaSource(MateriaSource &);
	~MateriaSource(void);
	MateriaSource	&operator=(MateriaSource &);

	void learnMateria(AMateria*);
	AMateria	*createMateria(std::string const &);
};
#endif