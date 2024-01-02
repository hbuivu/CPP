/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:46:20 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/02 13:46:21 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
	:	_type("AMateria")
{
}

AMateria::AMateria(const std::string& type)
	:	_type(type)
{
}

AMateria::AMateria(const AMateria& src)
	:	_type(src._type)
{
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=(const AMateria& src)
{
	this->_type = src._type;
	return *this;
}

const std::string&	AMateria::getType() const
{
	return(_type);
}

void	AMateria::use(ICharacter& target) //why is this not const?
{
	(void) target;
	std::cout << "raw material AMateria cannot be used" << std::endl;
}

/****************************************/

Ice::Ice()
	:	AMateria()
{
	_type = "ice";
}

Ice::Ice(const Ice& src)
	:	AMateria(src)
{
}

Ice::~Ice()
{
}

Ice&	Ice::operator=(const Ice& src)
{
	this->_type = src._type;
	return *this;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "*shoot an ice bolt at " << target.getName() << "*" << std::endl;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this)); 	
}

/****************************************/

Cure::Cure()
	:	AMateria()
{
	_type = "cure";
}

Cure::Cure(const Cure& src)
	:	AMateria(src)
{
}

Cure::~Cure()
{
}

Cure&	Cure::operator=(const Cure& src)
{
	this->_type = src._type;
	return *this;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "*heals " << target.getName() << "'s wounds*" << std::endl;
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}


/*
NOTES:
we can create a pointer to a paramaterized object using the constructor
ex: class A(const A& src) <- copy constructor
new A(src);

override keyword is used in c++11 and later. we cannot use it in 98, AS MUCH AS I WOULD LIKE TO
*/