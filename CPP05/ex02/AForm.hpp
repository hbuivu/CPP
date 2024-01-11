/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:00:55 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/05 18:00:55 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signedGrade;
	const int			_execGrade;
public:
	AForm();
	AForm(const std::string& name, const int sg, const int eg);
	AForm(const AForm& src);
	AForm(const std::string);
	virtual ~AForm();

	AForm&	operator=(const AForm& src);

	const std::string&	getName() const;
	bool				getSigned() const;
	int					getSignedGrade() const;
	int					getExecGrade() const;
	void				beSigned(const Bureaucrat& person);
	void				checkExec(const Bureaucrat& executor) const;
	virtual void		execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw(){ return "Form grade too high."; }
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw(){ return "Form grade too low."; }
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw(){ return "Form not signed"; }
	};

	class ExecutorGradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw(){ return "Executor's grade too low"; }
	};

	class FormAlreadySignedException : public std::exception
	{
	public:
		const char *what() const throw(){ return "Form already signed"; }
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm&src);

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