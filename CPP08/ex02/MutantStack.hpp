/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:56:51 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/18 09:33:30 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iterator>
# include <stack>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack<T, Container>(MutantStack<T, Container> const & src);
	MutantStack<T, Container> & operator=(MutantStack<T, Container> const & rhs);

	// typedef typename Container::iterator iterator;
	// typedef typename Container::const_iterator const_iterator;
	// typedef typename Container::reverse_iterator reverse_iterator;
	// typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// // c is the underlying container
	// iterator begin() {return this->c.begin();}
	// iterator end() {return this->c.end();}
	// const_iterator begin() const {return this->c.begin();}
	// const_iterator end() const {return this->c.end();}
	// reverse_iterator rbegin() {return this->c.rbegin();}
	// reverse_iterator rend() {return this->c.rend();}
	// const_reverse_iterator rbegin() const {return this->c.rbegin();}
	// const_reverse_iterator rend() const {return this->c.rend();}

}

#endif

/* NOTES:
Stack - LIFO - last in first out
stack is a container adapter - wrapper for an underlying container
push and pop elements from top of stack
	push will add element to top of stack
	pop will delete the most recent entered element

Uses for a stack:
	Function call management(call stack) - 
		when function is called, local var and info are pushed onto stack. when function is completed, info popped off stack
	Expression evaluation - artithmetic expressions
	Undo mechanism in software
	Backtracking Algorithm
	memory management 

The std::stack class has a member named c that represents the underlying container it uses to store elements.
*/
