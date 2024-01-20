/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:35:14 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/17 21:32:01 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
	// std::cout << "FIND MAX:\n";
	// std::cout << max(1, 4) << "\n";
	// std::cout << max(3.5f, 2.5f) << "\n";
	// std::cout << max(6.789, 6.899) << "\n";
	// std::cout << "FIND MIN:\n";
	// std::cout << min(1, 4) << "\n";
	// std::cout << min(3.5f, 2.5f) << "\n";
	// std::cout << min(6.789, 6.899) << "\n";
	// std::cout << "SWAP:\n";
	// int i = 0;
	// int j = 5;
	// swap(&i, &j);
	// float f = 10.5f;
	// float g = 11.43f;
	// swap(&f, &g);
	// std::cout << "i: " << i << " j: " << j << " f: " << f << " g: " << g << "\n";

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
