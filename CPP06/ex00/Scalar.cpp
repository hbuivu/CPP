/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:58:01 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/07 16:58:01 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(){}

Scalar::Scalar(const Scalar& src){ (void)src; }

Scalar::~Scalar(){}

Scalar&	Scalar::operator=(const Scalar& src)
{
	(void)src;
	return *this;
}

bool	Scalar::isInvalidChar(char c)
{
	return (c < '0' ||  c > '9') && c != '.' && c != 'f';
}

bool	Scalar::isMisplacedF(std::string::const_iterator& it, const std::string& literal)
{
	std::string::const_iterator it2 = it + 1;
	return *it == 'f' && it2 != literal.end();
}

void	Scalar::checkValidNum(const std::string& literal)
{
	int	decimalPoint = 0;
	std::string::const_iterator it = literal.begin();
	if (*it == '-' || *it == '+')
		it++;
	for (; it != literal.end(); ++it)
	{
		if (*it == '.')
			decimalPoint++;
		if (decimalPoint > 1 || isInvalidChar(*it) || isMisplacedF(it, literal))
			throw invalidInputException();
	}
}

void	Scalar::checkValidStr(const std::string& literal)
{
	if (literal.length() > 5)
		throw invalidInputException();
	if (literal != "nan" && literal != "nanf" && literal != "inf" && literal != "+inf" &&
		literal != "-inf" && literal != "inff" && literal != "+inff" && literal != "-inff")
		throw invalidInputException();
}

//returns 1 if char, 2 if num, 3 if string
int	Scalar::checkString(const std::string& literal)
{
	char firstElem = literal.at(0);
	char secondElem = literal.at(1);

	if ((firstElem < '0' || firstElem > '9') && literal.length() == 1)
		return 1; 
	else if ((firstElem >= '0' && firstElem <= '9') || 
			(firstElem == '-' && secondElem != 'i') || 
			(firstElem == '+' && secondElem != 'i'))
	{
		checkValidNum(literal);
		return 2;
	}
	else
	{
		checkValidStr(literal);
		return 3;
	}
	return (0);
}

void	Scalar::convertChar(const std::string& literal)
{
	char c = *(literal.begin());
	std::cout	<< "char: '" << c << "'\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n"
				<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

/* check for whole numbers. if wholenum, must have one decimal point after num. 
otherwise, print out as many decimals as allowed 
strtold converts string to long double */
void	Scalar::convertNum(const std::string& literal)
{
	bool wholeNum 	= false;
	long double	num = strtold(literal.c_str(), NULL);

	if (std::floor(num) == num)
		wholeNum = true;
	if (wholeNum == false || (num > 127 || num < 0))
		std::cout << "char: impossible\n";
	else if ((num >= 0 && num <= 31) || num == 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: " << static_cast<char>(num) << "\n";
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(num) << '\n';
	if (num > FLT_MAX || num < -FLT_MAX)
		std::cout << "float: impossible\n";
	else if (wholeNum == true)
		std::cout	<< "float: " << std::fixed << std::setprecision(1)
					<< static_cast<float>(num) << "f\n";
	else
		std::cout << "float: " << static_cast<float>(num) << "f\n";
	if (num > DBL_MAX || num < -DBL_MAX)
		std::cout << "double: impossible\n";
	else if (wholeNum == true)
		std::cout	<< "double: " << std::fixed << std::setprecision(1)
					<< static_cast<double>(num) << "\n";
	else
		std::cout << "double: "	<< static_cast<double>(num) << "\n";	
}

void	Scalar::convertStr(const std::string& literal)
{
	std::cout	<< "char: impossible\n"
				<< "int: impossible\n";
	if (literal == "nan" || literal == "nanf")
		std::cout	<< "float: nanf\n"
					<< "double: nan" << std::endl;
	else if (literal == "-inf" || literal == "-inff")
		std::cout	<< "float: -inff\n"
					<< "double: -inf" << std::endl;
	else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
		std::cout	<< "float: +inff\n"
					<< "double: +inf" << std::endl;
}

void	Scalar::convert(const std::string& literal)
{
	try
	{
		int i = checkString(literal);
		switch(i)
		{
			case 1: convertChar(literal); break;
			case 2: convertNum(literal); break;
			case 3: convertStr(literal); break;
			default: break;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

/* NOTES:
std::string - at(index) allows you to access letter at index but will throw an exception if nothing is available
switch statements only apply to numbers in C++98. we can use strings in C++17
iterators are a bit like pointers, but they are not exactly pointers as they are more generalized. Also some may not support pointer math
use const_iterator for const strings
explicit type conversion means using static cast

STILL NEED TO FIX:
with large numbers we lose accuracy
Test instantiation


The issue you're encountering is related to the fact that the number "2147483647" 
is at the edge of representable integers for a 32-bit float. 
When converting it using std::stof, the precision loss occurs, and you get the next 
representable floating-point value, which is "2147483648.0".

Float has less bits of precision than double (and same for double to long double), and so having larger numbers will start to result in precision loss 	
*/