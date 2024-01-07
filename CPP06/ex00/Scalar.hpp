/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:37:07 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/07 16:37:07 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <string>

class Scalar
{
private:
	Scalar();
	Scalar(const Scalar& src);
	~Scalar();

	Scalar&	operator=(const Scalar& src);
	
	static void	convertChar(const std::string& literal);
	static void	convertNum(const std::string& literal);
public:
	static void	convert(std::string literal) const;

	class invalidInputException : public std::exception 
	{
	public:
		const char* what() const throw() {return "Input is invalid."};
	}

};

#endif

/* NOTES:
What is a static class?
can't be instantiated - so set constructor/destructor to private
all members are static
*/

/* 
-detect type
-convert to appropriate type
-from og type, convert to other types using static_cast
characters should be anything printable except for numbers
numbers can be characters as long as they fall within the 255 (also there's negative ascii)
*/
