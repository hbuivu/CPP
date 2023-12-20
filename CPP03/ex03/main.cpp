/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:33:08 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/21 00:33:08 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("A");
	// DiamondTrap b("B");
	// DiamondTrap c(a);

	a.attack("Ben");
	a.beRepaired(100);
	a.takeDamage(10);
	a.whoAmI();

}