/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:07:19 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/06 01:07:19 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("Presidential Pardon", 25, 5),
		_target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:	AForm("Presidential Pardon", 25, 5),
		_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	:	AForm(src),
		_target(src._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	this->_target = src._target;
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	(void)executor;
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox\n";
}