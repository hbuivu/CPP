/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:01:12 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/05 18:01:12 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	:	_name("Default"),
		_signed(false),
		_signedGrade(75),
		_execGrade(75)
{
}

AForm::AForm(const std::string& name, const int sg, const int eg)
	:	_name(name),
		_signed(false),
		_signedGrade(sg),
		_execGrade(eg)
{
	if (_signedGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	else if (_signedGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	
}

AForm::AForm(const AForm& src)
	:	_name(src._name),
		_signed(src._signed),
		_signedGrade(src._signedGrade),
		_execGrade(src._execGrade)
{
	if (_signedGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	else if (_signedGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(const AForm& src)
{
	if (src._signedGrade < 1 || src._execGrade < 1)
		throw GradeTooHighException();
	else if (src._signedGrade > 150 || src._execGrade > 150)
		throw GradeTooLowException();
	this->_signed = src._signed;
	return *this;
	// this->_signedGrade = src._signedGrade; can't be done bc these are constant
	// this->_execGrade = src._execGrade;
}

const std::string&	AForm::getName() const
{
	return _name;
}

bool	AForm::getSigned() const
{
	return _signed;
}

int	AForm::getSignedGrade() const
{
	return _signedGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void	AForm::beSigned(const Bureaucrat& person)
{
	if (person.getGrade() > _signedGrade)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::checkExec(const Bureaucrat& executor) const
{
	if (this->getSigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const AForm&src)
{
	os	<< "Name: " << src.getName() << "; "
		<< "Signed: " << src.getSigned() << "; "
		<< "Signed Grade: " << src.getSignedGrade() << "; "
		<< "Execution Grade: " << src.getExecGrade() << std::endl;
	return (os);
}