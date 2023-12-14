/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:12:45 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 16:12:45 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./SedIsForLosers <filename> <stringToReplace> <stringReplacement>" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cout << "WARNING: stringToReplace cannot be empty" << std::endl;
		return (1);
	}
	Sed s = Sed(argv[1], argv[2], argv[3]);
	s.replace();
}