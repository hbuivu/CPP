/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:38:34 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 15:38:34 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
Weapon::Weapon()
{
}

Weapon::Weapon(std::string newType)
	:	_type(newType)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}

/* NOTES:
If a function is returning a ref, you can just return the object, as the ref and obj are the same
a getter gets private members for public use
a setter allows users to set private members
*/