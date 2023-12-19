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
	std::cout << "Fixed point default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
	:	_fixedPointValue(src._fixedPointValue)
{
	std::cout << "Fixed point copy constructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& src)
{
	std::cout << "Fixed point copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src._fixedPointValue;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Fixed point destructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	_fixedPointValue = num << _fractionalBits;
	std::cout << "Fixed point int parameter constructor called" << std::endl;	
}

Fixed::Fixed(const float num)
{
	_fixedPointValue = roundf(num * (1 << _fractionalBits));
	std::cout << "Fixed point float parameter constructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
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

// //preincrement
// Fixed&	Fixed::operator++ (void)
// {
// 	this->_fixedPointValue++;
// 	return (*this);
// }

// //postincrement
// Fixed&	Fixed::operator++(int i)
// {
// 	Fixed	temp(*this);
	
// 	temp->_fixedPointValue++;
// 	return (temp);
// }

// //preincrement
// Fixed&	Fixed::operator-- (void)
// {
// 	this->_fixedPointValue--;
// 	return (*this);
// }

// //postincrement
// Fixed&	Fixed::operator--(int i)
// {
// 	Fixed	temp(*this);
	
// 	temp->_fixedPointValue--;
// 	return (temp);
// }


// static Fixed&	min(Fixed& a, Fixed& b)
// {
// 	if (a < b)
// 		return (a);
// 	return (b);
// }

// static Fixed&	min(const Fixed a, const Fixed b)
// {
// 	if (a < b)
// 		return (a);
// 	return (b);
// }

// static Fixed&	max(Fixed& a, Fixed& b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }

// static Fixed&	max(const Fixed a, const Fixed b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }


