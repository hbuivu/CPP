/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:42:15 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/18 14:20:57 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array()
	:	_size(0),
		_array(NULL)
{	
}

template <typename T>
Array<T>::Array(unsigned int n)
	:	_size(n),
		_array(new T[n]()) 
{
}

template <typename T>
Array<T>::Array(const Array& src)
	:	_size(src._size)
{
	this->_array = new T[this->_size];
	std::copy(src._array, src._array + src._size, this->_array);
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
size_t	Array<T>::size() const
{
	return _size;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& src)
{
	if (this != &src)
	{
		delete[] this->_array;
		this->_size = src._size;
		this->_array = new T[this->_size]();
		std::copy(src._array, src._array + src._size, this->_array);
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](const size_t& index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_array[index]);
}

#endif

/* NOTES:
https://stackoverflow.com/questions/38000073/why-must-i-declare-template-above-each-function-in-a-template
5

Member functions of a templated class require template so they can specify the class' template, even if the function itself isn't templated. This is because the class isn't class MyClass, but template<typename T> class MyClass<T>, but the functions don't know that by default. Because of this, the compiler needs to know what the class' template parameters are so it can associate the function with the actual class, allowing it to do things such as make the correct version of the member function's this pointer, or allow the function to use the class' template parameter list.

This is necessary because templates aren't raw code, they're blueprints for code, which the compiler uses to make the actual code whenever it needs to instantiate or otherwise use them.
*/