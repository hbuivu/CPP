/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:07:43 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/19 14:07:43 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& src);
	~Fixed();
	Fixed&	operator= (const Fixed& src);
	
	Fixed(const int num);
	Fixed(const float num);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

	bool	operator> (const Fixed& src) const;
	bool	operator< (const Fixed& src) const;
	bool	operator>= (const Fixed& src) const;
	bool	operator<= (const Fixed& src) const;
	bool	operator== (const Fixed& src) const;
	bool	operator!= (const Fixed& src) const;

	Fixed	operator+ (const Fixed& src) const;
	Fixed	operator- (const Fixed& src) const;
	Fixed	operator* (const Fixed& src) const;
	Fixed	operator/ (const Fixed& src) const;

	Fixed&  operator++ (); //pre increment
    Fixed   operator++ (int); // post increment
    Fixed&  operator-- (); 
    Fixed   operator-- (int); 

	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

};

std::ostream&	operator<< (std::ostream& os, const Fixed& src);

typedef struct s_Point
{
	Fixed	x;
	Fixed	y;
}	Point;

typedef struct s_Triangle
{
	Point&	p1;
	Point&	p2;
	Point&	p3;
}	Triangle;

bool	BSP(Triangle& t, Point& p);

#endif
