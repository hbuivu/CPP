/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:07:38 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/19 14:07:38 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	:	_fixedPointValue(0)
{
	// std::cout << "Fixed point default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
	:	_fixedPointValue(src._fixedPointValue)
{
	// std::cout << "Fixed point copy constructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& src)
{
	// std::cout << "Fixed point copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src._fixedPointValue;
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Fixed point destructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	_fixedPointValue = num << _fractionalBits;
	// std::cout << "Fixed point int parameter constructor called" << std::endl;	
}

Fixed::Fixed(const float num)
{
	_fixedPointValue = roundf(num * (1 << _fractionalBits));
	// std::cout << "Fixed point float parameter constructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" <<std::endl;
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
	// std::cout << "setRawBits member function called" << std::endl;
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

int	Fixed::toInt() const
{
	return (_fixedPointValue >> _fractionalBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& src) const
{
	return (this->_fixedPointValue > src._fixedPointValue);
}

bool	Fixed::operator<(const Fixed& src) const
{
	return (this->_fixedPointValue < src._fixedPointValue);
}

bool	Fixed::operator>=(const Fixed& src) const
{
	return (this->_fixedPointValue == src._fixedPointValue);
}

bool	Fixed::operator<=(const Fixed& src) const
{
	return (this->_fixedPointValue <= src._fixedPointValue);
}

bool	Fixed::operator==(const Fixed& src) const
{
	return (this->_fixedPointValue == src._fixedPointValue);
}

bool	Fixed::operator!=(const Fixed& src) const
{
	return (this->_fixedPointValue != src._fixedPointValue);
}

Fixed	Fixed::operator+ (const Fixed& src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed	Fixed::operator- (const Fixed& src) const
{
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed	Fixed::operator* (const Fixed& src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed	Fixed::operator/ (const Fixed& src) const
{
	return Fixed(this->toFloat() / src.toFloat());
}

//preincrement
/* 
int i = 5;
int value = ++i
i is incremented first then value is assigned to value*/
Fixed&	Fixed::operator++ ()
{
	++this->_fixedPointValue;
	return (*this);
}

//postincrement
/* 
int i = 5;
int value = i++;
current value of i (5) assigned to value, then i is incremented*/
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	
	this->_fixedPointValue++;
	return (temp);
}

//preincrement
Fixed&	Fixed::operator-- ()
{
	--this->_fixedPointValue;
	return (*this);
}

//postincrement
Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	
	this->_fixedPointValue--;
	return (temp);
}


Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}
