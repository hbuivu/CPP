/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:04:37 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/13 12:05:09 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	for (int i = 1; i < argc; i++)
		for (int j = 0; argv[i][j]; j++)
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
	std::cout << std::endl;
	return (0);	
}

/* NOTES:
argv is a c-style string, we must convert to a c++ string if we want to use it as a cstyle string
we static_cast<char> toupper because toupper returns an int and technically takes an int char
*/

// int main(int argc, char **argv)
// {
// 	if (argc == 1)
// 	{
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
// 		return (0);
// 	}
// 	for (int i = 1; i < argc; i++)
// 	{
// 		std::string str{argv[i]};
// 		for (int j = 0; j < str.length(); j++)
// 			std::cout << static_cast<char>(std::toupper(str[j]));
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }