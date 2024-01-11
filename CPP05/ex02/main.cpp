/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:22 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/11 16:25:06 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	/* 
	SHRUBBERY: sign 145, exec 137
	ROBOTOMY: sign 72, exec 45
	PRESIDENT: sign 25, exec 5
	*/
	try
	{
		Bureaucrat A("A", 72);
		std::cout << A << " created successfully\n";
		ShrubberyCreationForm S("newshrubs");
		RobotomyRequestForm R("Rob");
		PresidentialPardonForm P("Patrick");
		
		A.signForm(S); //Everything here will execute bc try catch statement is in signform and execute form functions
		A.executeForm(S);
		A.signForm(R);
		A.executeForm(R);
		A.signForm(P);
		A.executeForm(P);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}