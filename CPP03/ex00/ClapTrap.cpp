/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:57:41 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 20:57:41 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:	_hitPts(10),
		_energyPts(10),
		_attackDmg(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string* name)
	:	_hitPts(0),
		_energyPts(0),
		_attackDmg(0)
{
	(void)name;
	std::cout	<< "ClapTrap only takes an std::string parameter. Please review your input."
				<< "An incomplete ClapTrap object has been formed" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	:	_name(name),
		_hitPts(10),
		_energyPts(10),
		_attackDmg(0)
{
	std::cout << "ClapTrap str parameter constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
	:	_name(src._name),
		_hitPts(src._hitPts),
		_energyPts(src._energyPts),
		_attackDmg(src._attackDmg)
{
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPts = src._hitPts;
		this->_energyPts = src._energyPts;
		this->_attackDmg = src._attackDmg;
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
	std::cout 	<< "<ClapTrap> " << _name << " attacks " << target << " causing " << _attackDmg 
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
	std::cout	<< "<ClapTrap> " << _name << " took " << amount << " points of damage and now has " 
				<< _hitPts << " hit points!" << std::endl; 
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
	std::cout	<< "<ClapTrap> " << _name  << " regained " << amount << " hit points and now has a total of " 
				<< _hitPts << " hit points!" << std::endl;
}
