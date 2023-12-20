/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:07:48 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/19 14:07:48 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "Max is " << Fixed::max( a, b ) << std::endl;

	// Fixed a(10);
	// Fixed b(20);
	// // Fixed c(a);
	
	// // std::cout << c.getRawBits() << std::endl;
	// // std::cout << (10 << 8) << std::endl;
	// std::cout << (b > a) << "\n";
	// std::cout << (b > a) << "\n";
	
	// Fixed c = a + b;
	// std::cout << c.toFloat() << "\n";

	// std::cout << "using fixed max function:" << Fixed::max(a, b) << "\n";


	return 0;
}