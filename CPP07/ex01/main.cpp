/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:14 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/17 21:40:44 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main()
{
	int a1[] = {5, 6, 7, 7, 8, 9, 10};
	int len1 = 7;
	char a2[] = "Hello World";
	int len2 = 11;
	std::string a3[] = {"cat", "dog", "mouse"};
	int len3 = 3;
	double a4[] = {3.45, 6.88, 9.99, 2.34, 1.567, 9.1, 3.045, 10.111};
	int len4 = 8;
	::iter(a1, len1, &printElement);
	std::cout << "\n";
	::iter(a2, len2, &printElement);
	std::cout << "\n";
	::iter(a3, len3, &printElement);
	std::cout << "\n";
	::iter(a4, len4, &printElement);
}
