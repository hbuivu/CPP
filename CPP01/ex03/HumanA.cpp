/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:37:19 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 15:37:19 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA::HumanA() why is this an error
// {
// }

HumanA::HumanA(std::string name, Weapon& weapon)
	:	_name(name), 
		_weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	if (_weapon.getType().empty())
		std::cout << _name << " attacks with nothing " << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

/* NOTES:
list initialization is true initialization
when setting things inside of constructor body, you are setting the variable not initializing it
*/