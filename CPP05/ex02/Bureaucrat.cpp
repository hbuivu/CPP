/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:18 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/11 16:20:36 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:	_name("Default"),
		_grade(75)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	:	_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	:	_name(src._name)
{
	if (src._grade < 1)
		throw GradeTooHighException();
	else if (src._grade > 150)
		throw GradeTooLowException();
	_grade = src._grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (src._grade < 1)
		throw GradeTooHighException();
	else if (src._grade > 150)
		throw GradeTooLowException();
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

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed form " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr	<< _name << " couldn't sign form " 
					<< form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.checkExec(*this);
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << " form." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< _name << " couldn't execute form "
					<< form.getName() << " because " << e.what() << std::endl;
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
