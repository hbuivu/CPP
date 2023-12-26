/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:27:53 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/26 18:36:14 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:	Animal()
{
	_type = "Cat";
	std::cout << "<Cat> default constructor called" << std::endl;
}

Cat::Cat(const Cat& src)
	:	Animal(src)
{
	this->_type = src._type;
	std::cout << "<Cat> copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "<Cat> destructor called" << std::endl;
}


Cat&	Cat::operator=(const Cat& src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "<Cat> copy assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
