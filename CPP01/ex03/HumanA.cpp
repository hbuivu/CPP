#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : m_name(name), m_weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	if (this->m_weapon.getType().empty())
		std::cout << this->m_name << " attacks with nothing " << std::endl;
	else
		std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}

/* NOTES:
initialize outside of constructor {} - look up why later
*/