/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:35 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/05 18:00:35 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signedGrade;
	const int			_execGrade;
public:
	Form();
	Form(const std::string& name, const int sg, const int eg);
	Form(const Form& src);
	Form(const std::string);
	~Form();

	Form&	operator=(const Form& src);

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getSignedGrade() const;
	int					getExecGrade() const;
	void				beSigned(const Bureaucrat& person);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw(){
			return "Grade too high. The highest possible grade is 150\n";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw(){
			return "Grade too low. The lowest possible grade is 150\n";
		}
	};
};

std::ostream&	operator<<(std::ostream& os, const Form&src);

#endif

/* NOTES:
it is only necessary to use virtual once - afterwards, any derived functions will be automatically virtual
even with more than one hierarchy of classes. In c++11, use the override keyword in derived classes to make it clear that the function is virtual
unfortunately we don't have that functionality in C__98

const ints must ALWAYS be initialized, otherwise cannot compile (test this later)
normal ints do not need to be initialized but will have garbage values

const int getSigned - we get a const type qualifier on return type has no effect
Because the function returns a prvalue. There is no difference between const and nonconst prvalues of type int or bool.
*/