/* NOTES: 
A copy constructor is used to init an object with an existing object of the same type 
ExampleClass (const ExampleClass& exClass) -> it contains a reference to the same class
call with ExampleClass copyClass {existingObject};
use =delete if you want to supress a copy constructor (object cannot be copied

copy assignment operator (=) -> used to copy values from one object to another existing object
basically like a copy constructor except its for something that already exists
must be overloaded as  member function
exampleClass& operator = const exampleClass& exampleclass
*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	//this is the value of the number if binary point is at 0
	int	_fixedPointValue;
	//static const - init one only does not need to be init again
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& CopyFPN);
	~Fixed();
	Fixed& operator= (const Fixed& OgFPN);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
