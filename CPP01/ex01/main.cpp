/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:56:42 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 14:56:42 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *horde = zombieHorde(10, "Sam");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	// for (int i = 0; i < 10; i++)
	// 	horde[i].~Zombie();
	delete[] horde;
}