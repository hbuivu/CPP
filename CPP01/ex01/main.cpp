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
	int num = 10;
	Zombie *horde = zombieHorde(num, "Sam");
	for (int i = 0; i < num; i++)
		horde[i].announce();
	// for (int i = 0; i < 10; i++)
	// 	horde[i].~Zombie();
	delete[] horde;
}