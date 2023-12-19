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
	//Check for correct number of arguments
	if (argc != 4)
	{
		std::cout << "Usage: ./Sed <filename> <stringToReplace> <stringReplacement>" << std::endl;
		return (1);
	}
	//Check if stringtoreplace is empty
	if (std::string(argv[2]).empty())
	{
		std::cout << "WARNING: stringToReplace cannot be empty" << std::endl;
		return (1);
	}
	//check if the file exists or is a directory
	struct stat	s;
	if (stat(argv[1], &s) != 0)
	{
		std::cout << "File does not exist" << std::endl;
		return (1);
	}
	if (s.st_mode & S_IFDIR)
	{
		std::cout << "This file is a directory" << std::endl;
		return (1);
	}
	//run Sed
	Sed sed = Sed(argv[1], argv[2], argv[3]);
	sed.replace();
}

/* TESTS:
nonexistent file
empty file
directory
change permissions file
replace "a" with "a"
replace "a" with "aba"
replace "" with "a"
replace "a" with ""
*/