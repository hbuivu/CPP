#include "ICharacter.hpp"

Character::Character()
{
}

Character::Character(const std::string& name)
	:	_name(name),
		_materia(NULL)

Character::Character(const Character& src)
	:	_name(src._name)
{
}

Character::~Character()
{

}

Character&	Character::operator=(const Character &src)
{
	this->_name = src._name;
}

const std::string&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{

}

void	unequip(int idx)
{

}

void	use(int idx, ICharacter& target)
{

}
