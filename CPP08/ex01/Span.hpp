/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:59 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/23 16:32:19 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>

class Span
{
private:
	unsigned int		_size;
	std::vector<int>	_array;
	
public:
	Span();
	explicit Span(unsigned int N); //use explicit keyword for single parameter constructor. see more below
	Span(const Span& src);
	~Span();

	Span&	operator=(const Span& src);
	
	void	addNumber(const int i);
	int		shortestSpan();
	int		longestSpan() const;
	
	template <class IT>
	void	addSequence(IT start, IT end)
	{
		if (std::distance(start, end) + _array.size() > _size)
			throw FullArrayException();
		_array.insert(_array.end(), start, end);	
	};

	class	FullArrayException : public std::exception{
	public:
		const char* what() const throw() {return "Array is full";};
	}; 
	class	NoSpanException : public std::exception{
	public:
		const char *what() const throw() {return "No span found";};
	};
};

#endif

/* NOTES:
Sequential containers:
maintains order of elements
can choose where to insert element by position
simple insertion of elements take O(1) - constant time
inserting elements in the middle is slower than in associative containers
1. Array
	array<T, n>
	containers of fixed size
2. Vector
	vector<T>
	dynamic size
	random access via []
	can insert and remove from the end
3. Deque
	deque<T>
	dynamic size
	double ended queue class
	can insert and remove from both ends
4. Forward list
	forward_list<T>
	singly linked list
	allow insert and erase in constant time anywhere in the sequence
5. List
	list<T>
	doubly linked list

Associative:
automatically sorts inputs using operator <
inserting, removing, searching for an element takes O(log n) time
Incrementing/decrementing iterator takes O(1) amortized time
inserting elements in middle faster than sequence containers
1. Set
	every element (key) is unique
	an inserted key cannot be odifed
	key can be removed
2. Map
	stores key-value pairs
	keys must be uniue and can only have one value associated with key
	data type of key and value may be different
	can add or remove elements from any position
3. Multiset
	allows dups unlike set
4. Multimap
	allows dups unlike map

Unordered
same as associative but unordered
position of the element does not matter
these elements are accessed using hash

Container Adapters - applied to existing containers as wrappers
1. stack
2. queue
3. priority queue

<string> implicitly contains <algorithm> header (maybe)

Using explicit keyword:
ex: 
foo(class(int));
foo(5); <- without explicit, foo will automatically initialize class to 5 and pass it as a parameter
*/