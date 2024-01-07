/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:03 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/06 01:36:11 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("Shrubbery", 145, 137),
		_target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	:	AForm("Shrubbery", 145, 137),
		_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	:	AForm(src),
		_target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	this->_target = src._target;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	// if (this->getSigned() == false)
	// 	throw FormNotSignedException();
	// else if (executor.getGrade() > this->getExecGrade())
	// 	throw GradeTooLowException();
	checkExec(executor);
	std::string	name = _target + "_shrubbery";
	std::ofstream outfile(name.c_str());
	if (outfile.is_open())
	{
		outfile << "Placeholder tree\n";
		outfile.close();
	}
	else
		throw std::ios_base::failure("Failed to open output file"); //???
}

