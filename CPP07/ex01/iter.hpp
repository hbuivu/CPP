/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:29 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/18 15:01:40 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>
# include <iostream>

template<typename A, typename F>
void	iter(A* array, size_t length, F func)
{
	for (size_t iterator = 0; iterator < length; iterator++)
		func(array[iterator]);
}

template<typename T>
void	printElement(T& element)
{
	std::cout << element << " ";
}

#endif

/* NOTES:
The act of creating a new definition of a function, class, or member of a class from a template declaration and one or more template arguments is called template instantiation. 
The definition created from a template instantiation to handle a specific set of template arguments is called a specialization.

template <typename T> void func(T param) {} // definition
template void func<int>(int param); // explicit instantiation - used when you only want it to work with a couple of types

template <typename T> void func(T param) {} // definition
template <> void func<int>(int param) {} // specialization

Template instantiation has two forms: explicit instantiation and implicit instantiation.
*/

// template<typename T>
// void iter(T* array, size_t length, void (*f)(T& element))
// {
// 	for (size_t iterator = 0; iterator < length; iterator++)
// 		(*f)(array[iterator]);
// }