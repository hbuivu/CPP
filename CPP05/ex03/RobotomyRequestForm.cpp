/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:19:10 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/06 00:19:10 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("Robotomy", 72, 45),
		_target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:	AForm("Robotomy", 72, 45),
		_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	:	AForm(src),
		_target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	this->_target = src._target;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	// if (this->getSigned() == false)
	// 	throw FormNotSignedException();
	// else if (executor.getGrade() > this->getExecGrade())
	// 	throw GradeTooLowException();
	(void)executor;
	std::cout << "*Makes drilling noises*\n";
	bool success = rand() % 2;
	if (success == true)
		std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << _target << "'s robotomy has failed\n";
}

