#include "Fixed.hpp"
//default constructor
Fixed::Fixed()
	:	_fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;	
	_fixedPointValue = num << _fractionalBits;
}

//scale float value by 2^fractionalBits (left shift bits)
//bitwise operation cannot be applied to floats
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(num * (1 << _fractionalBits)); //should i round here?
}

//copy constructor
Fixed::Fixed(const Fixed& CopyFPN)
	:	_fixedPointValue(CopyFPN._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& ogFPN)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ogFPN)
		this->_fixedPointValue = ogFPN.getRawBits();
	return (*this);
}

//gets _fixedPointValue
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return (this->_fixedPointValue);
}

//sets _fixedPointValue
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream&	operator<< (std::ostream& os, const Fixed& OgFPN)
{
	os << OgFPN.toFloat();
	return (os);
}

bool	operator> (const Fixed& OgFPN)
{
	return (this.getRawBits() > OgFPN.getRawBits());
}

bool	operator< (const Fixed& OgFPN)
{
	return (this.getRawBits() < OgFPN.getRawBits());
}

bool	operator>= (const Fixed& OgFPN)
{
	return (this.getRawBits() >= OgFPN.getRawBits());
}

bool	operator<= (const Fixed& OgFPN)
{
	return (this.getRawBits() <= OgFPN.getRawBits());
}

bool	operator== (const Fixed& OgFPN)
{
	return (this.getRawBits() == OgFPN.getRawBits());
}

bool	operator!= (const Fixed& OgFPN)
{
	return (this.getRawBits() !=OgFPN.getRawBits());
}

Fixed	operator+ (const Fixed& OgFPN)
{
	return (this.toFloat() + OgFPN.toFloat());
}

Fixed	operator- (const Fixed& OgFPN)
{
	return (this.toFloat() - OgFPN.toFloat());
}

Fixed	operator* (const Fixed& OgFPN)
{
	return (this.toFloat() * OgFPN.toFloat());
}

Fixed	operator/ (const Fixed& OgFPN)
{
	return (this.toFloat() / OgFPN.toFloat());
}

//preincrement
Fixed&	operator++ (void)
{
	this->_fixedPointValue++;
	return (*this);
}

//postincrement
Fixed&	operator++(int i)
{
	Fixed	temp(*this);
	
	temp->_fixedPointValue++;
	return (temp);
}

//preincrement
Fixed&	operator-- (void)
{
	this->_fixedPointValue--;
	return (*this);
}

//postincrement
Fixed&	operator--(int i)
{
	Fixed	temp(*this);
	
	temp->_fixedPointValue--;
	return (temp);
}


static Fixed&	min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

static Fixed&	min(const Fixed a, const Fixed b)
{
	if (a < b)
		return (a);
	return (b);
}

static Fixed&	max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

static Fixed&	max(const Fixed a, const Fixed b)
{
	if (a > b)
		return (a);
	return (b);
}


