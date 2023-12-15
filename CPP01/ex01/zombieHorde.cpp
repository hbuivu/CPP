/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:58:43 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 14:58:43 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i] = Zombie(name); //temp copy created here
	return (horde);
}

/* NOTES:
when using the default copy constructor, a temp obj is created. temp obj is used to create new obj. temp obj is destroyed
1. Zombie(name) creates a temp Zombie object
2. assignmnet operator (=) copies the temp Zombie object into horde array
when dynamically allocating an array, c++ does not use of constructor with parameters
*/