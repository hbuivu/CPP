#include "FragTrap.hpp"

FragTrap::FragTrap()
	:	ClapTrap()
{
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
	:	ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
	std::cout<< "Fragtrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy)
{
	this->_name = cpy._name;
	this->_hitPts = cpy._hitPts;
	this->_energyPts = cpy._energyPts;
	this->_attackDmg = cpy._attackDmg;
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for  " << _name << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "<FragTrap> " << _name << " wants to give everyone a high five!" << std::endl;
}