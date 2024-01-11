/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:22 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/11 13:41:28 by hbui-vu          ###   ########.fr       */
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
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat C("C", 2);
		std::cout << C << " created successfully\n";
		C.incrementGrade();
		std::cout << C << " incremented grade succesfully!\n";
		C.incrementGrade();	
		std::cout << C << " incremented grade succesfully!\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat C("C", 149);
		std::cout << C << " created successfully\n";
		C.decrementGrade();
		std::cout << C << " decremented grade succesfully!\n";
		C.decrementGrade();	
		std::cout << C << " decremented grade succesfully!\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}