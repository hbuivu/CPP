/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:29 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/05 18:00:29 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	:	_name("Default"),
		_signed(false),
		_signedGrade(75),
		_execGrade(75)
{
}

//signedGrade and execGrade are const, so must be intialized in list
Form::Form(const std::string& name, const int sg, const int eg)
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

Form::Form(const Form& src)
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

Form::~Form()
{
}

//can't copy over signedGrade or execGrade bc they are constants
Form&	Form::operator=(const Form& src)
{
	if (src._signedGrade < 1 || src._execGrade < 1)
		throw GradeTooHighException();
	else if (src._signedGrade > 150 || src._execGrade > 150)
		throw GradeTooLowException();
	this->_signed = src._signed;
	return *this;
}

const std::string&	Form::getName() const
{
	return _name;
}

bool	Form::getSigned() const
{
	return _signed;
}

int	Form::getSignedGrade() const
{
	return _signedGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void	Form::beSigned(const Bureaucrat& person)
{
	if (person.getGrade() > _signedGrade)
		throw ExecutorGradeTooLowException();
	if (_signed == true)
		throw FormAlreadySignedException();
	_signed = true;
}

std::ostream&	operator<<(std::ostream& os, const Form&src)
{
	os	<< "Name: " << src.getName() << "; "
		<< "Signed: " << src.getSigned() << "; "
		<< "Signed Grade: " << src.getSignedGrade() << "; "
		<< "Execution Grade: " << src.getExecGrade();
	return (os);
}