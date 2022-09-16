#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	AMateria		*ice1 = new Ice();
	AMateria		*ice2 = new Ice();
	AMateria		*ice3 = new Ice();
	AMateria		*ice4 = new Ice();
	AMateria		*cure1 = new Cure();
	AMateria		*cure2 = new Cure();
	AMateria		*cure3 = new Cure();
	AMateria		*cure4 = new Cure();

	src->learnMateria(ice1);
	src->learnMateria(ice2);
	src->learnMateria(cure1);
	src->learnMateria(cure2);
	src->learnMateria(ice3);
	src->learnMateria(cure3);
	src->learnMateria(ice4);
	src->learnMateria(cure4);

	ICharacter	*me = new Character("me");
	AMateria	*tmp1, *tmp2, *tmp3, *tmp4, *tmp5, *tmp6;

	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	tmp3 = src->createMateria("ice");
	me->equip(tmp3);
	tmp4 = src->createMateria("cure");
	me->equip(tmp4);
	tmp5 = src->createMateria("ice");
	me->equip(tmp5);
	tmp6 = src->createMateria("cure");
	me->equip(tmp6);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(-1, *bob);
	me->use(9999, *bob);

	me->unequip(-1);
	me->unequip(9999);
	me->unequip(0);
	me->unequip(1);
	me->unequip(9999);
	me->unequip(3);
	me->unequip(2);
	me->unequip(-1);
	me->unequip(9999);

	delete bob;
	delete me;
	delete src;
	delete ice3;
	delete ice4;
	delete cure3;
	delete cure4;
	delete tmp1;
	delete tmp2;
	delete tmp3;
	delete tmp4;
	delete tmp5;
	delete tmp6;

	Character	*c1 = new Character("c1");
	c1->equip(new Cure);
	Character	*c2 = new Character("c2");
	*c2 = *c1;
	delete (c1);
	delete (c2);
	system("leaks program");
	return 0;
}
