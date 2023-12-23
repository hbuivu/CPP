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
	// std::cout << "hitpts energypts attackdmg: " << _hitPts <<  _energyPts << _attackDmg << std::endl;
	// FragTrap::_hitPts = 100;
	// ScavTrap::_energyPts = 50;
	// FragTrap::_attackDmg = 30;
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 30;
	std::cout << "DiamondTrap parameter constructor called for " << _name <<  std::endl;
}

/* NOTES:
DiamondTrap seems to take the last build, which is ScavTrap build
ScavTrap FragTrap and ClapTrap all share the same variable _name. There is only one _name variable
That's why if you change the _name in S, F, or C, the _name will be changed for all three
similarly, _hitPts, _energyPts, and _attackDmg is a shared variable between all four classes
*/

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
	std::cout	<< "<DiamondTrap>" << _name << " is experiencing an existential crisis! " 
				<< "Could its name be " << ClapTrap::_name << " instead?" << std::endl;
}
