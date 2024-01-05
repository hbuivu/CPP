#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const int sg, const int eg);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operation=(const RobotomyRequestForm& src);
};

#endif