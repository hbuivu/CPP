/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:25:54 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/23 13:38:03 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

int main() 
{
	try
	{
		Span sp = Span(20);
		sp.addNumber(6); 
		sp.addNumber(3); 
		sp.addNumber(17); 
		sp.addNumber(9); 
		sp.addNumber(11);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; 
		std::cout << sp.longestSpan() << std::endl;

		int arr [] = {1, 2, 3, 4, 5, 6, 7, 8, 20, 9};
		std::vector<int> vct(arr, arr + (sizeof(arr) / sizeof(int)));
		sp.addSequence(vct.begin(), vct.end());
		
		std::cout << sp.shortestSpan() << std::endl; 
		std::cout << sp.longestSpan() << std::endl;	

		sp.addSequence(arr, arr + (sizeof(arr) / sizeof(int)));
		std::cout << sp.shortestSpan() << std::endl; 
		std::cout << sp.longestSpan() << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0; 
}