/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:27:53 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/27 14:36:44 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:	Animal(),
		_brain(new Brain)
{
	_type = "Cat";
	std::cout << "<Cat> default constructor called" << std::endl;
}

Cat::Cat(const Cat& src)
	:	Animal(src),
		_brain(new Brain (*(src._brain)))
{
	this->_type = src._type;
	std::cout << "<Cat> copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "<Cat> destructor called" << std::endl;
}


Cat&	Cat::operator=(const Cat& src)
{
	this->_type = src._type;
	if (this != &src)
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*(src._brain));
	}
	std::cout << "<Cat> copy assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
