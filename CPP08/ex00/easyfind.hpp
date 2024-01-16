/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:39:40 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/15 14:39:40 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <cstdlib>

//returns a pointer to array.cend() if can't find i
template<typename T>
typename T::const_iterator	easyfind(const T& array, int i)
{
	typename T::const_iterator it = array.cbegin();
	for (; it != array.cend(); it++)
	{
		if (*it == i)
			return (it);
	}
	return (it);
};

#endif

/* NOTES:
why is T<int>::const_iterator wrong?
typename keyword is used to indicate that a dependent name is a type
dependent name - nested type - any name that depends on a type containing a template parameter 
	ex: std::vector<int>::size_type not std::size_type
		std::vector<int>::const_iterator not std::const_iterator
	std::vector<T> is a type with a template parameter, so std::vector<T>::size_type 
	is a nested type and considered a dependent name
		->therefore, when using it in a template, must have typename before it

T is already the template type, we do not need to provide any additional template info
*/