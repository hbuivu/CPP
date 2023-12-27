/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:47:51 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/27 14:48:56 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:	Animal(),
		_brain(new Brain)
{
	_type = "Dog";
	std::cout << "<Dog> default constructor called" << std::endl;
}

Dog::Dog(const Dog& src)
	:	Animal(src),
		_brain(new Brain(*(src._brain)))
{
	this->_type = src._type;
	std::cout << "<Dog> copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "<Dog> destructor called" << std::endl;
}


Dog&	Dog::operator=(const Dog& src)
{
	this->_type = src._type;
	if (this != &src)
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*(src._brain));
	}
	std::cout << "<Dog> copy assignment operator called" << std::endl;
	return *this;
}

void	Dog::makeSound() const //virtual only has to be declared when creating class
{
	std::cout << "Woof" << std::endl;
}
