/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 01:45:57 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/06 01:45:57 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
# include <iostream>

class Intern
{
public:
	Intern();
	Intern(const Intern& src);
	~Intern();

	Intern&	operator=(const Intern& src);

	AForm*	makeForm(const std::string& form, const std::string& target) const;
	
	class FormNotRecognizedException : public std::exception
	{
	public:
		const char *what() const throw() { return "Form not recognized"; }
	};
};

#endif