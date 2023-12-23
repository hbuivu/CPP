/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:39:10 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 22:39:10 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	_energyPts = 555;
	_hitPts = 555;
	_attackDmg = 555;
	std::cout<< "Fragtrap parameter constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
	:	ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPts = src._hitPts;
		this->_energyPts = src._energyPts;
		this->_attackDmg = src._attackDmg;
	}
	std::cout << "FragTrap copy assignment operator called for " << _name << std::endl;
	return (*this);
}
void	FragTrap::highFivesGuys()
{
	std::cout << "<FragTrap> " << _name << " wants to give everyone a high five!" << std::endl;
}