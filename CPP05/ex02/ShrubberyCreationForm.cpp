/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:03 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/05 19:10:40 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("Shrubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	:	AForm(src)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
// {
// 	this->_name = src._name;
// 	this->_signed = src._signed;
// 	return *this;
// }

void	createShrubbery(const std::string& target)
{
	std::string	name = target + "_shrubbery";
	std::ofstream outfile(name);
	if (outfile.is_open())
		outfile << /* tree ascii file*/
	outfile.close()
	
}

