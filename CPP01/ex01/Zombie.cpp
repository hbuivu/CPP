#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout << "Destroyed " << this->m_name <<std::endl;
}

void	Zombie::setName(std::string name)
{
	this->m_name = name;
}

void	Zombie::announce(void) const
{
	std::cout << this->m_name <<": BraiiiiiiinnnzzzZ..." <<std::endl;
}