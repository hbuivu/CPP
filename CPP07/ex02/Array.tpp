/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:42:15 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/10 19:58:14 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::Array()
	:	_size(0),
		_array(NULL)
{}

Array::Array(unsigned int n)
	:	_size(n),
		_array(new T[n])
{}

Array::Array(const Array& src)
	:	_size(src._size)
{
	this->_array = new T[this->_size];
	std::copy(src._array, src._array + src._size, this->_array);
}

Array::~Array(){}

Array&	Array::operator=(const Array& src)
{
	if (this != &src)
	{
		delete [] this->_array;
		this->_size = src._size;
		this->_array = new T[this->_size];
		std::copy(src._array, src._array + src._size, this->_array);
	}
	return *this;
}