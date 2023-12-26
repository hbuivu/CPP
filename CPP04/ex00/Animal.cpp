/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:26:31 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/26 18:39:50 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	:	_type("animal")
{
	std::cout << "<Animal> default constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	this->_type = src._type;
	std::cout << "<Animal> copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "<Animal> destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "<Animal> copy assignment operator called" << std::endl;
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "Animal Noise" << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}
