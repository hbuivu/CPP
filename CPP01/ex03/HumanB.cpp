/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:37:34 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 15:37:34 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
}

HumanB::HumanB(std::string name)
	: 	_name(name),
		_weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
void	HumanB::attack() const
{
	if (!_weapon || _weapon->getType().empty())
		std::cout << _name << " does not have a weapon." << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}