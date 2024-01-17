/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:56:51 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/17 15:58:17 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iterator>
# include <stack>

class MutantStack
{
private:
	std::stack	_stack;
public:
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
*/
