/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:27:28 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 21:27:28 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a = ClapTrap("Amy");
	ClapTrap b = ClapTrap("Bob");
	ClapTrap c = ClapTrap(b);
	a.attack("Rob");
	b.attack("Pamy");
	c.attack("Ted");
	a.takeDamage(20);
	a.beRepaired(20);
	b.beRepaired(2);
	c = a;
	c.attack("Becky");
	c.takeDamage(5);
}