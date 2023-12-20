/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:07:05 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 23:07:05 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:	ClapTrap(), FragTrap(), ScavTrap()
{
	_hitPts = FragTrap::_hitPts;
	_energyPts = ScavTrap::_energyPts;
	_attackDmg = FragTrap::_attackDmg;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	:	ClapTrap(name), FragTrap(name), ScavTrap(name),
		_name(name)
{
	ClapTrap::_name = name + "_clap_name"; //this sets the name of the ClapTrap base to something else
	// _hitPts = FragTrap::_hitPts; //100
	// _energyPts = ScavTrap::_energyPts; //50
	// _attackDmg = FragTrap::_attackDmg; //30
	FragTrap::_hitPts = 100;
	ScavTrap::_energyPts = 50;
	FragTrap::_attackDmg = 30;
	std::cout << "DiamondTrap parameter constructor called for " << _name <<  std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
	:	ClapTrap(src), FragTrap(src), ScavTrap(src),
		_name(src._name)
{
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPts = src._hitPts;
		this->_energyPts = src._energyPts;
		this->_attackDmg = src._attackDmg;
	}
	std::cout << "DiamondTrap copy assignment operator called for " << _name << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "<DiamondTrap>" << _name << " is experiencing an existential crisis" << std::endl;
}


