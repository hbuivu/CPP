#include "HumanB.hpp"

HumanB::HumanB(std::string name) : m_name(name)
{
	this->m_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->m_weapon = &weapon;
}
void	HumanB::attack() const
{
	if (!this->m_weapon || this->m_weapon->getType().empty())
		std::cout << this->m_name << " does not have a weapon." << std::endl;
	else
		std::cout << this->m_name << " attacks with their " << this->m_weapon->getType() << std::endl;
}