/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:31:36 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 21:31:36 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	:	ClapTrap()
{
	_hitPts = 100; //_hitPts is already initialized, now we are assigning that variable different values
	_energyPts = 50;
	_attackDmg = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) 
	:	ClapTrap(name)
{
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
	std::cout << "ScavTrap parameter constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string* name)
	:	ClapTrap(name)
{
	std::cout	<< "ScavTrap only takes an std::string parameter. Please review your input."
				<< "An incomplete ScavTrap object has been formed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src)
	:	ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src) //this is technically not necessary if no dynamically allocated memory is in play
	{
		this->_name = src._name;
		this->_hitPts = src._hitPts;
		this->_energyPts = src._energyPts;
		this->_attackDmg = src._attackDmg;
	}
	std::cout << "ScavTrap copy assignment operator called for " << _name << std::endl; 
	return *this;
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
	std::cout	<< "<ScavTrap> " << _name << " attacks " << target << " causing " << _attackDmg 
				<< " points of damage and has " << _energyPts << " energy points left!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "<ScavTrap> " << _name << " is in gatekeeper mode!" << std::endl;
}