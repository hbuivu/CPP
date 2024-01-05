#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const int sg, const int eg);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operation=(const PresidentialPardonForm& src);
};

#endif