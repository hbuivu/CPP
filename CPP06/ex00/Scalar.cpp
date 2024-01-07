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

void	Scalar::convertNum(std::string literal) const
{
	int i = std::stoi(literal);
	if (i >= -128 && i <= 127)
		std::cout << "char: " << static_cast<char>i << "\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout	<< "int: " << i << "\n";
				<< "float: " << std::stof(literal) << "f\n";
				<< "double: " << std::stod(literal) << std::endl;
}

void	Scalar::convertChar(std::string literal) const
{
	char c = literal[0];
	std::cout	<< "char: '" << c << "'\n";
				<< "int: " << static_cast<int>c << "\n";
				<< "float" << static_cast<float>c << "f\n";
				<< "double: " << static_cast<double>c << std:;endl;
}

void	Scalar::convert(std::string literal) const
{
	char	firstElem = literal.at(0);
	
	
	if (firstElem >= '0' && firstElem <= '9')
	{
		try
		{
			char decimalPoint = 0;
			bool isChar = (literal[i] < '0' ||  literal[i] > '9') && literal[i] != '.' && literal[i] != 'f';
			bool isMisplacedF = literal[i] == 'f' && i != literal.length() - 1;
			for (int i = 0; literal[i]; i++)
			{
				if (literal[i] == '.')
					decimalPoint++;	
				if	(decimalPoint > 1 || isChar || isMisplacedF)
					throw invalidInputException();
			}
			convertNum(literal);
		}
		catch(const std::exception& e)
			std::cerr << e.what() << '\n';
	}
	else
	{
		try
		{
			if (literal.length() > 1)
				throw invalidInputException();
			convertChar(literal);
		}
		catch(const std::exception& e)
			std::cerr << e.what() << '\n';
	}
}

/* NOTES:
std::string - at(index) allows you to access letter at index but will throw an exception if nothing is available
*/