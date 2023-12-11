#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->m_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Destroyed " << this->m_name <<std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->m_name <<": BraiiiiiiinnnzzzZ..." <<std::endl;
}