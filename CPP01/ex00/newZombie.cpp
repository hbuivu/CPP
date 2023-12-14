/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:39:45 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 14:39:45 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie (std::string name)
{
	Zombie*	newZombie = new Zombie(name);
	return (newZombie);
}

/* NOTES:
new returns a pointer - it allocates memory and calls the constructor of the object
use delete to free - it will call the destructor
if allocating with square brackets, delete with square brackets
there is also placement new - look that up later
*/