/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:06:37 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/19 14:06:37 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int	_fixedPointValue; //val of number if binary point is at 0
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& CopyFPN);
	~Fixed();
	Fixed& operator= (const Fixed& src);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif

/* NOTES: 
A copy constructor is used to init an object with an existing object of the same type 
ExampleClass (const ExampleClass& exClass) -> it contains a reference to the same class
call with ExampleClass copyClass {existingObject};
use =delete if you want to supress a copy constructor (object cannot be copied

copy assignment operator (=) -> used to copy values from one object to another existing object
basically like a copy constructor except its for something that already exists
must be overloaded as  member function
exampleClass& operator = const exampleClass& exampleclass

static variables are used for the entire class rather than for individual instances of each class
has to be initiated inside declaration of class rather than in constructor
*/
