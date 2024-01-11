/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:49:12 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/06 01:49:12 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
	(void)src;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

AForm*	Intern::makeForm(const std::string& form, const std::string& target) const
{
	AForm*	newForm;
	std::string formType[] = {"Shrubbery", "Robotomy", "Presidential Pardon"};
	int i = -1;
	while (++i < 3)
		if (formType[i] == form)
			break;
	if (i == 3)
		throw FormNotRecognizedException();
	switch (i) 
	{
		case 0: newForm = new ShrubberyCreationForm(target); break;
		case 1: newForm = new RobotomyRequestForm(target); break;
		case 2: newForm = new PresidentialPardonForm(target); break;
		default: newForm = NULL; break;
	}
	std::cout << "Intern creates form " << newForm->getName() << std::endl;
	return (newForm);
}

	// switch (i)
	// {
	// 	case 0:
	// 	{
	// 		newForm = new ShrubberyCreationForm(target);
	// 		break;
	// 	}
	// 	case 1:
	// 	{
	// 		newForm = new RobotomyRequestForm(target);
	// 		break;
	// 	}
	// 	case 2:
	// 	{
	// 		newForm = new PresidentialPardonForm(target);
	// 		break;
	// 	}
	// 	default:
	// 	{
	// 		newForm = NULL;
	// 		break;
	// 	}
	// }