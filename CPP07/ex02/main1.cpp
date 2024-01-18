/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:34:24 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/12 18:31:06 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	try
	{
		Array<char>arr1(100);
		arr1[0] = 'a';
		arr1[1] = 'b';
		arr1[2] = 'c';
		for (int i = 0; i < 4; i++)
			std::cout << arr1[i] << "\n";
		
		Array<std::string>arr2(5);
		arr2[0] = "apple";
		arr2[1] = "pear";

		for (int i = 0; i < 3; i++)
			std::cout << arr2[i] << "\n";
		// Array<int>array(10);
		// std::cout << array[5] << "\n";
		// array[1] = 100;
		// std::cout <<array[1] << "\n"
		// std::cout << array[10];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
	
}