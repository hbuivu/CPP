/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:37:07 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/07 16:37:07 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <cfloat>
# include <climits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter();

	ScalarConverter&	operator=(const ScalarConverter& src);

	static void	checkValidNum(const std::string& literal, int& decPlaces);
	static int	checkString(const std::string& literal, int& decPlaces);
	static void	convertChar(const std::string& literal);
	static void	convertNum(const std::string& literal, int& decPlaces);
	static void	convertStr(const std::string& literal);
public:
	static void	convert(const std::string& literal);

	class invalidInputException : public std::exception 
	{
	public:
		const char* what() const throw() {return "Input is invalid.";};
	};
};

#endif

/* NOTES:
What is a static class?
can't be instantiated - so set constructor/destructor to private
all members are static

implicit cast - automatically casting from one type to another (int -> float for example)
promotion casts (type widening) - conversion of a type from a smaller type to a larger type (float -> double)
static cast - a way for the programmer to explicitly cast one compatible type to another
dynamic cast - used for casting within class hierarchies
*/

