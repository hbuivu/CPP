/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:03 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/11 14:58:39 by hbui-vu          ###   ########.fr       */
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
	checkExec(executor);
	std::string	name = _target + "_shrubbery";
	std::ofstream outfile(name.c_str());
	if (outfile.is_open())
	{
		outfile	<<	"    *\n"
				<<	"   ***\n"
				<<	"  *****\n"
				<<	" *******\n"
				<<	"*********\n"
				<<	"   |||\n" ;
		outfile.close();
	}
	else
		throw std::ios_base::failure("Failed to open output file");
}

