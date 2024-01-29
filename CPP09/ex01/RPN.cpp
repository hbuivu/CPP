#include "RPN.hpp"

std::stack<long double>	RPN::_stack;

RPN::RPN()
{
}

RPN::RPN(const RPN& src)
{
	(void)src;
}

RPN::~RPN()
{
}

RPN&	RPN::operator=(const RPN& src)
{
	(void)src;
	return *this;
}

void RPN::calcRPN(std::string const & statement)
{
	for (std::string::const_iterator it = statement.begin(); it != statement.end(); it++)
	{
		if (*it >= '0' && *it <= '9')
			_stack.push(*it - '0');
		else if (*it == '/' || *it == '+' || *it == '-' || *it == '*')
		{
			if (_stack.size() < 2)
				throw InvalidStatementException();
			_stack.push(applyOperator(*it));
		}
		else if (*it != ' ')
			throw InvalidStatementException();
	} 
	if (_stack.size() != 1)
		throw InvalidStatementException();
	std::cout << _stack.top() << "\n";
}

long double RPN::applyOperator(char sign)
{
	long double num1 = _stack.top();
	_stack.pop();
	long double num2 = _stack.top();
	_stack.pop();
	long double finalValue = 0.0;
	switch(sign)
	{
		case '+': finalValue = num2 + num1; break;
		case '-': finalValue = num2 - num1; break;
		case '*': finalValue = num2 * num1; break;
		case '/': 
			if (num1 == 0)
				throw DivideByZeroException();
			finalValue = num2 / num1;
			break;
		default: break;
	}
	if (finalValue > DBL_MAX || finalValue < -(DBL_MAX))
		throw ReturnValueOverflowException();
	return (finalValue);
}