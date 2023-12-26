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
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a is " << a << std::endl;
	std::cout << "++a is " << ++a << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "a++ is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "Max is " << Fixed::max( a, b ) << std::endl;
	std::cout << "Min is " << Fixed::min(a, b) << std::endl;
	std::cout << (b > a) << std::endl;
	std::cout << (b < a) << std::endl;
	std::cout << b + a << std::endl;
	std::cout << b - a << std::endl;
	std::cout << b * a << std::endl;
	return 0;
}