/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:05:55 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/19 14:05:55 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	:	_fixedPointValue(0)
{
	std::cout << "Fixed Point default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
	:	_fixedPointValue(src._fixedPointValue)
{
	std::cout << "Fixed point copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Fixed point destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src._fixedPointValue;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_fixedPointValue = raw;
}
