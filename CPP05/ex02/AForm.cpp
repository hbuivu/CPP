#include "AForm.hpp"

Form::Form()
	:	_name("Default"),
		_signed(false),
		_signGrade(75),
		_execGrade(75)
{
}

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

Form&	operator=(const Form& src)
{
	if (src._signedGrade < 1 || src._execGrade < 1)
		throw GradeTooHighException();
	else if (src._signedGrade > 150 || src._execGrade > 150)
		throw GradeTooLowException();
	this->_signed = src._signed;
	this->_signedGrade = src._signedGrade;
	this->_execGrade = src._execGrade;
}

const std::string&	getName() const
{
	return _name;
}

bool	getSigned() const
{
	return _signed;
}

const int	getSignedGrade() const
{
	return _signedGrade;
}

const int getExecGrade() const
{
	return getExecGrade;
}

void				beSigned(const Bureaucrat& person)
{
	if (person.getGrade() > _signedGrade)
		throw GradeTooLowException();
	_signed = true;
}

std::ostream&	operator<<(std::ostream& os, const Form&src)
{
	os	<< "Name: " << src.getName() << "; "
		<< "Signed: " << src.getSigned() << "; "
		<< "Signed Grade: " << src.getSignedGrade() << "; "
		<< "Execution Grade: " << src.getExecGrade() << std::endl;
	return (os);
}