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
		// horde[i] = Zombie(name); //temp copy created here
		new (&horde[i]) Zombie(name);
	return (horde);
}

/* NOTES:
when using the default copy constructor, a temp obj is created. temp obj is used to create new obj. temp obj is destroyed
1. Zombie(name) creates a temp Zombie object
2. assignmnet operator (=) copies the temp Zombie object into horde array
when dynamically allocating an array, c++ does not use of constructor with parameters

Instead of creating multiple temp copies, we can use PLACEMENT NEW
Normal new allocates memory and constructs an object in that memory
Placement new - pass pre-allocated memory and construct an object in that passed memory
	ex: new (&horde[i]) Zombie(name)
		&horde[i] - memory address
		Zombie(name) - call constructor
Technically when calling placement new, we also need to call the destructor for each object constructed
However, at least in the laptop linux, this seems to be unnecessary
*/