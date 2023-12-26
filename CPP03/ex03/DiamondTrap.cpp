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
	:	ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	:	ClapTrap(name), ScavTrap(name), FragTrap(name),
		_name(name)
{
	ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap parameter constructor called for " << _name <<  std::endl;
}

DiamondTrap::DiamondTrap(std::string* name)
	:	ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout	<< "ScavTrap only takes an std::string parameter. Please review your input." 
			<< "An incomplete ScavTrap object has been formed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src)
	:	ClapTrap(src), ScavTrap(src), FragTrap(src),
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
		this->ClapTrap::_name = src.ClapTrap::_name; //don't forget to copy over override variables!!!
		this->ScavTrap::_energyPts = src.ScavTrap::_energyPts;
	}
	std::cout << "DiamondTrap copy assignment operator called for " << _name << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout	<< "<DiamondTrap>" << _name << " is experiencing an existential crisis! " 
				<< "Could its name be " << ClapTrap::_name << " instead?" << std::endl;
}

/* NOTES:
DiamondTrap seems to take the last build, which is ScavTrap build
ScavTrap FragTrap and ClapTrap all share the same variable _name. There is only one _name variable
That's why if you change the _name in S, F, or C, the _name will be changed for all three
similarly, _hitPts, _energyPts, and _attackDmg is a shared variable between all four classes
*/