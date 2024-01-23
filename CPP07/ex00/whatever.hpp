/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:35:19 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/23 16:26:39 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T> //template parameter declaration, needs to be declared above each template function
void swap(T& x, T& y)
{
	T tmp (x); //default constructor could be deleted or private; STL uses copy constructor so it wouldn't compile if copy constructor was also not available
	// tmp = x;
	x = y;
	y = tmp;
}

template <typename T> 
T min(T x, T y) { return (x < y)? x : y; };

template <typename T>
T max(T x, T y) { return (x > y)? x : y; };

#endif

/* NOTES:
a function template reduces the need to write overloaded functions
ex: a template function to find the max would work with int, double, float, etc
types are not determined until template is used in program
A function template is a function-like definition that is used to generate one or more overloaded functions, each with a different set of actual types. 
This is what will allow us to create functions that can work with many different types.

Note that using only typename T means that return value and parameter values all have to be the same type
solutions:
	max<double>(2, 3.5);
	max(static_cast<double>(2), 3.5);
	template <typename T, typename U>
	T max(T x , U y); -> this can result in conversion problem, esp with return of T. -> use auto return type here

*/