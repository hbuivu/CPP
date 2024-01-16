/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:01:58 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/15 16:21:08 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

int main()
{
	{
		int array_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::vector<int> array(array_data, array_data + sizeof(array_data) / sizeof(array_data[0]));
		
		std::vector<int>::const_iterator it = easyfind(array, 10);
		(void)it;
		if (it == array.cend())
			std::cout << "last\n";
		else
			std::cout << *it <<	"\n";
	}
	
	{
		int array_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::deque<int> array(array_data, array_data + sizeof(array_data) / sizeof(array_data[0]));
		std::deque<int>::const_iterator it = easyfind(array, 8);
		(void)it;
		if (it == array.cend())
			std::cout << "last\n";
		else
			std::cout << *it <<	"\n";
	}
	
}