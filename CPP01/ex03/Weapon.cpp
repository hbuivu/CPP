#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
	Weapon::setType(newType);
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return (this->m_type);
}

void	Weapon::setType(std::string newType)
{
	this->m_type = newType;
}

/* NOTES:
If a function is returning a ref, you can just return the object, as the ref and obj are the same
a getter gets private members for public use
a setter allows users to set private members
*/