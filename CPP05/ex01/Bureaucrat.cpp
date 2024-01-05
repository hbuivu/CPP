/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:18 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/05 17:59:14 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:	_name("Default"),
		_grade(75)
{
	std::cout << "default constructor should not be called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	:	_name(name),
		_grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	:	_name(src._name),
		_grade(src._grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	// this->_name = src._name; //we can't do this bc _name is const
	if (src._grade < 1)
		throw GradeTooHighException();
	else if (src._grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = src._grade;
	return (*this);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << "signed form " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << _name << "couldn't sign form " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat&src)
{
	os << src.getName() << ", bureaucrat grade: " << src.getGrade();
	return (os);
}

/* Once a throw is detected, the rest of the code does not execute
all try blocks must have at least one associated catch block
*/
