/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:14 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/10 18:59:07 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void add_two(int i)
{
	std::cout << i + 2 << "\n";
}

int main()
{
	int array[] = {5, 6, 7, 7, 8, 9, 10};
	int len = 7;
	::iter(array, len, &add_two);

	// char *str = "hello world\n";
	// size_t length = 12;
	// ::iter(array, length, )
}