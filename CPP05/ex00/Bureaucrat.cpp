/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:18 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/04 19:11:09 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:	_grade(0)
{
	std::cout << "default constructor should not be called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	:	_name(name),
		_grade(grade)
{
	if (_grade < _HIGHESTGRADE)
		throw GradeTooHighException();
	else if (_grade > _LOWESTGRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	:	_name(src._name),
		_grade(src._grade)
{
	if (_grade < _HIGHESTGRADE)
		throw GradeTooHighException();
	else if (_grade > _LOWESTGRADE)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	// this->_name = src._name; //we can't do this bc _name is const
	if (src._grade < _HIGHESTGRADE)
		throw GradeTooHighException();
	else if (src._grade > _LOWESTGRADE)
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

void	Bureaucrat::incrementGrade(int incr)
{
	int newGrade = _grade + incr;
	if (newGrade < _HIGHESTGRADE)
		throw GradeTooHighException();
	else if (newGrade > _LOWESTGRADE)
		throw GradeTooLowException();
	else
		_grade = newGrade;
}

void	Bureaucrat::decrementGrade(int decr)
{
	int newGrade = _grade - decr;
	if (newGrade < _HIGHESTGRADE)
		throw GradeTooHighException();
	else if (newGrade > _LOWESTGRADE)
		throw GradeTooLowException();
	else
		_grade = newGrade;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat&src)
{
	os << src.getName() << ", bureaucrat grade: " << src.getGrade();
	return (os);
}
