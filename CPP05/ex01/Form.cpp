#include "Form.hpp"

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
	if (_signedGrade < 1)
		throw GradeTooHighException();
	else if (_signedGrade )
}

Form::Form(const Form& src)
	:	_name(src._name),
		_signed(src._signed),
		_signedGrade(src._signedGrade),
		_execGrade(src._execGrade)
{
}

Form::~Form()
{
}

Form&	operator=(const FOrm&src)
{

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

std::ostream&	operator<<(std::ostream& os, const Form&src)
{
	os	<< "Name: " << src.getName() << "; "
		<< "Signed: " << src.getSigned() << "; "
		<< "Signed Grade: " << src.getSignedGrade() << "; "
		<< "Execution Grade: " << src.getExecGrade() << std::endl;
	return (os);
}