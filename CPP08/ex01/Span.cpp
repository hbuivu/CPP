/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:56 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/15 18:46:09 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* NOTES: CHECK copy constructors!! */

#include "Span.hpp"

Span::Span(){}

Span::Span(int N)
	:	_size(N)
{
}

Span::Span(const Span& src)
	:	_size(src._size),
		_array(src._array)
{
}

Span::~Span(){}

Span&	Span::operator=(const Span& src)
{
	this->_size = src._size;
	this->_array = src._array;
}

void	addNumber(const int i)
{
	//insert	
}

void	addSequence()
{
	//insertRange
}
