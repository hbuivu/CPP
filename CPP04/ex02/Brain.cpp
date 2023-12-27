/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:17:17 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/27 12:02:28 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::copy(src._ideas, src._ideas + 100, this->_ideas);
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& src)
{
	if (this != &src)
		std::copy(src._ideas, src._ideas + 100, this->_ideas);
	return *this;
}

/* NOTES: 
arrays need to be copied over one by one
use the std::copy function which copies elements in the range(first, last, destination)
*/