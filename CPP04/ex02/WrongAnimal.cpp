/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:48:24 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/27 10:48:25 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	:	_type("wrong animal")
{
	std::cout << "<WrongAnimal> default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "<WrongAnimal> destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	this->_type = src._type;
	std::cout << "<WrongAnimal> copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "<WrongAnimal> copy assignment operator called" << std::endl;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "A wrong animal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}
