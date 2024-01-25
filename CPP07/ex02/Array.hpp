/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:23:09 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/25 19:11:11 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <iostream>

template <typename T>
class Array
{
private:
	size_t	_size;
	T*		_array;
	
public:
	Array();
	Array(unsigned int n);
	Array(const Array& src);
	~Array();
	
	Array&	operator=(const Array& src);
	T&	operator[](const size_t& index);

	size_t	size() const;

	class OutOfBoundsException : public std::exception
	{
	public:
		const char *what() const throw(){return "Element out of bounds";}
	};
};

#include "Array.tpp"
#endif

/* NOTES:
a class template is a template definition for instantiating class types
can be used on classes, structs, and unions
unlike functions, type definitions (variable members) cannot be overloaded

ex:
template <typename T>
struct Pair
{
	T first;
	T second;
}

Pair<int>p1(5, 6) ->instantiates a Pair<int>
Pair<double>p2(1.2, 3.4) ->instantiates a Pair<double>

ex: using class template in a function
int max(Pair<int>p);
or T max(Pair<T>p);

Templates are normally defined in .hpp or .tpp files
we don't use .cpp files bc templates are processed by the compiler at compile time
and compiler needs to see entire template definition (declaration and implementation) at poitn of instantiation
in a cpp file, the compiler would not be able to see implementation during compilation of source files

*/