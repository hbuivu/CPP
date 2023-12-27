/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:47:51 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/27 10:47:52 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:	Animal()
{
	_type = "Dog";
	std::cout << "<Dog> default constructor called" << std::endl;
}

Dog::Dog(const Dog& src)
	:	Animal(src)
{
	this->_type = src._type;
	std::cout << "<Dog> copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "<Dog> destructor called" << std::endl;
}


Dog&	Dog::operator=(const Dog& src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "<Dog> copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const //virtual only has to be declared when creating class
{
	std::cout << "Woof" << std::endl;
}
