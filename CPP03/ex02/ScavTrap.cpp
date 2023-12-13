#include "ScavTrap.hpp"

/* NOTE: consts and ref requires initialization, cannot be assigned in the body */

ScavTrap::ScavTrap()
	:	ClapTrap();
{
	_hitPts = 100; //_hitPts is already initialized, now we are assigning different values
	_energyPts = 50;
	_attackDmg = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
	:	ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy)
{
	this->_name = cpy._name;
	this->_hitPts = cpy._hitPts;
	this->_energyPts = cpy._energyPts;
	this->_attackDmg = cpy._attackDmg;
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPts == 0)
	{
		std::cout << "<ScavTrap> " << _name << "is dead and cannot attack!" << std::endl;
		return ;
	}
	if (_energyPts == 0)
	{
		std::cout << "<ScavTrap> " << _name << " does not have enough energy to attack!" << std::endl;
		return ;
	}
	_energyPts--;
	std::cout << "<ScavTrap> " << _name << " attacks " << target << " causing " << _attackDmg 
		<< " points of damage and has " << _energyPts << " energy points left!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "<ScavTrap> " << _name << " is in gatekeeper mode!" << std::endl;
}