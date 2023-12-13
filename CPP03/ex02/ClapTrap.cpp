#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:	_hitPts(10),
		_energyPts(10),
		_attackDmg(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:	_name(name),
		_hitPts(10),
		_energyPts(10),
		_attackDmg(0)
{
	std::cout << "ClapTrap constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy)
{
	this->_name = cpy._name;
	this->_hitPts = cpy._hitPts;
	this->_energyPts = cpy._energyPts;
	this->_attackDmg = cpy._attackDmg;
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& og)
{
	if (this != &og)
	{
		this->_name = og._name;
		this->_hitPts = og._hitPts;
		this->_energyPts = og._energyPts;
		this->_attackDmg = og._attackDmg;
	}
	std::cout << "ClapTrap copy assignment operator called for " << _name << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPts == 0)
	{
		std::cout << "<ClapTrap> " << _name << " is dead and cannot attack!" << std::endl;
		return ;
	}
	if (_energyPts == 0)
	{
		std::cout << "<ClapTrap> " << _name << " does not have enough energy to attack!" << std::endl;
		return ;
	}
	_energyPts--;
	std::cout << "<ClapTrap> " << _name << " attacks " << target << " causing " << _attackDmg 
		<< " points of damage and has " << _energyPts << " energy points left!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hitPts)
	{
		std::cout << "<ClapTrap> " << _name << " is dead and cannot take damage!" << std::endl;
		_hitPts = 0;
		return;
	}
	_hitPts -= amount;
	std::cout << "<ClapTrap> " << _name << " took " << amount << " points of damage and now has " << _hitPts << " hit points!" << std::endl; 
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPts == 0)
	{
		std:: cout << "<ClapTrap> " << _name << " is dead and cannot repair!" << std::endl;
		return ;
	}
	if (_energyPts == 0)
	{
		std::cout << "<ClapTrap> " << _name << " does not have enough energy to repair!" << std::endl;
		return ;
	}
	_energyPts--;
	_hitPts += amount;
	std::cout << "<ClapTrap> " << _name  << " regained " << amount << " hit points and now has a total of " << _hitPts << " hit points!" << std::endl;
}
