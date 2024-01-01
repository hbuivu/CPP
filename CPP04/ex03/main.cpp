#include "Amateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	AMateria *i = new Ice();
	AMateria *c = new Cure();
	src->learnMateria(i);
	src->learnMateria(c);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(0);
	me->unequip(0);
	me->unequip(1);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	Character::clearDroppedMateria();
	delete bob;
	delete me;
	delete src;
	delete i;
	delete c;

	return 0;
}
