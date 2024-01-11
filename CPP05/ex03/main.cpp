/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:22 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/11 16:56:02 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// "Shrubbery, Robotomy, Presidential Pardon"

int main()
{
	try
	{
		Intern I;
		std::cout << "Intern created for : ";
		Bureaucrat B("B", 1);
		std::cout << B << "\n";
		AForm* f1 = I.makeForm("Shrubbery", "shrubs");
		B.signForm(*f1);
		B.executeForm(*f1);
		delete f1;
		AForm* f2 = I.makeForm("Robotomy", "Ricky");
		B.signForm(*f2);
		B.executeForm(*f2);
		delete f2;
		AForm* f3 = I.makeForm("Presidential Pardon", "Perry");
		B.signForm(*f3);
		B.executeForm(*f3);
		delete f3;
		AForm* f4 = I.makeForm("Shrubberies", "shruberrish");
		B.signForm(*f4);
		B.executeForm(*f4);
		delete f4;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}