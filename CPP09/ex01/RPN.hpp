#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <cfloat>

class RPN
{
private:
	RPN();
	RPN(RPN const & src);
	~RPN();
	RPN&	operator=(RPN const & src);

	static long double	applyOperator(char sign);
public:
	static std::stack<long double>	_stack;
	
	static void	calcRPN(std::string const & statement);
	
	class InvalidStatementException : public std::exception{
		const char *what() const throw(){return "Invalid statement";}
		};
	class ReturnValueOverflowException : public std::exception{
		const char *what() const throw(){return "Return value too large";}
	};
};

#endif