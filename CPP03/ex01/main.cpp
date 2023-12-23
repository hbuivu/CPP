/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:31:24 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/20 21:31:24 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Tracy");
	ScavTrap b = a; //copy constructor bc b does not exist until it is set = to a
	ScavTrap c("Ben");
	ScavTrap d(c);
	b = d; //an existing object is now set to another object. copy assignment operator is used
	a.attack("Rob");
	a.guardGate();
	b.beRepaired(29);
	d.attack("Jill");
	d.beRepaired(40);
}