#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signedGrade;
	const int			_execGrade;
	Form();
public:
	Form(const Form& src);
	Form(const std::string)
	~Form();

	Form&	operator=(const Form& src);

	const std::string&	getName() const;
	bool				getSigned() const;
	const int			getSignedGrade() const;
	const int			getExecGrade() const;
	void				beSigned(Bureaucrat& person);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw(){
			return "Grade too high. The highest possible grade is 150\n";
		}
	}

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw(){
			return "Grade too low. The lowest possible grade is 150\n";
		}
	}
};

std::ostream&	operator<<(std::ostream& os, const Form&src);

#endif

/* NOTES:
it is only necessary to use virtual once - afterwards, any derived functions will be automatically virtual
even with more than one hierarchy of classes. In c++11, use the override keyword in derived classes to make it clear that the function is virtual
unfortunately we don't have that functionality in C__98

const ints must ALWAYS be initialized, otherwise cannot compile (test this later)
normal ints do not need to be initialized but will have garbage values
*/