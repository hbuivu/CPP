/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:38:34 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 14:38:34 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	//Stack Zombie
	Zombie z1("A");
	z1.announce();

	//randomchump
	randomChump("C");

	//Heap Zombie
	Zombie *z2 = newZombie("B");
	z2->announce();
	delete(z2);
}