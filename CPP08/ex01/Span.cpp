/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:56 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/22 15:24:30 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* NOTES: CHECK copy constructors!! */

#include "Span.hpp"

Span::Span()
	:	_size(0)
{
}

Span::Span(unsigned int N)
	:	_size(N)
{
}

Span::Span(const Span& src)
	:	_size(src._size),
		_array(src._array) 
{
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& src)
{
	this->_size = src._size;
	this->_array = src._array;//operator= is supported for multisets
	return *this;
}

void	Span::addNumber(const int i)
{
	if (_array.size() < _size)
		_array.insert(i);
	else
		throw FullArrayException();
}

int	Span::longestSpan() const
{
	if (_array.empty() || _array.size() == 1)
		throw NoSpanException();
	int max = *(std::max_element(_array.begin(), _array.end()));
	int min = *(std::min_element(_array.begin(), _array.end()));
	return (max - min);
}

int	Span::shortestSpan() const
{
	if (_array.empty() || _array.size() == 1)
		throw NoSpanException();
	int shortestSpan = -1;
	for (std::multiset<int>::iterator it = _array.begin(); it != std::prev(_array.end()); it++)
	{
		if (shortestSpan == -1 || (*(std::next(it))) - *it < shortestSpan)
			shortestSpan = *(std::next(it)) - *it;
		if (shortestSpan == 0)
			return shortestSpan;
	}
	return shortestSpan;
}

/* 
DRAFTS:
int	Span::longestSpan() const
{
	if (_array.empty() || _array.size() == 1)
		throw NoSpanException();
	int	first = *(_array.begin());
	int last = *(std::prev(_array.end()));
	return (last - first);
}
*/

