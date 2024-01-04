/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:22 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/04 19:24:54 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat A("A", 130);
		std::cout << A << " created successfully\n";
		Bureaucrat B("B", 160);
		std::cout << B << " created successfully\n";	
	}
	catch(const std::exception& e)
	{
		std::cerr << "something\n";
	}
	try
	{
		Bureaucrat C("C", 100);
		std::cout << C << " created successfully\n";	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}