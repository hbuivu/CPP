/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:22 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/11 16:17:25 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//signedGrade, executionGrade

int main()
{
	try
	{
		Bureaucrat A("A", 130);
		std::cout << A << " created successfully\n";
		Form F("AForm", 140, 30);
		std::cout << F << " created successfully\n";
		Form F1("AnotherForm", 30, 30);
		std::cout << F1 << " created successfully\n";
		A.signForm(F);
		A.signForm(F1);
		A.signForm(F);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		Form F2("ABadForm", 0, 151);
		std::cout << F2 << " created successfully\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}	
}