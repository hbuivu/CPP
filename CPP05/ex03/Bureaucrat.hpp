/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:01:15 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/06 01:25:45 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	
	Bureaucrat&	operator=(const Bureaucrat& src); 
	
	const std::string&	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(AForm &form) const;
	void				executeForm(const AForm& form) const;

	class	GradeTooHighException : public std::exception
	{
	public:
		const char*	what() const throw() {
			return "Grade too high. The highest possible grade is 1\n";
		};
	};
	
	class	GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw(){
			return "Grade too low. The lowest possible grade is 150\n";
		}
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat&src);

#endif