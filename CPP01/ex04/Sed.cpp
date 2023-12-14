/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:13:11 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 16:13:11 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string infile, std::string find, std::string replace) 
	:	_infile(infile),
		_find(find),
		_replace(replace)
{
	_outfile = _infile + ".replace";
}

Sed::~Sed()
{
}

void	Sed::replace()
{
	//check if file is a directory
	// std::filesystem::is_directory()
	struct stat	s;
	if (stat(_infile.c_str(), &s) != 0)
	{
		std::cout << "File does not exist" << std::endl;
		return ;
	}
	if (s.st_mode & S_IFDIR)
	{
		std::cout << "This file is a directory" << std::endl;
		return ;
	}
	//open file for reading
	std::ifstream	infile(_infile); //ifstream opens up a file for input
	if (infile.is_open())
	{
		//if infile is valid open outfile to be written into
		std::ofstream	outfile(_outfile); //ofstream opens up a file for output
		if (outfile.is_open())
		{
			//if s1 is the same as s2, copy files and exit
			if (_find.compare(_replace) == 0 || 
				infile.peek() == std::ifstream::traits_type::eof())
			{
				outfile << infile.rdbuf();
				outfile.close();
				infile.close();
				return ;
			}
			//stream contents of intfile into file - another method would be to getline the whole file into a string
			std::ostringstream contents;
			contents << infile.rdbuf();
			std::string stringContents = contents.str();
			size_t	pos = stringContents.find(_find);
			while (pos != std::string::npos)
			{
				stringContents.erase(pos, _find.length());
				stringContents.insert(pos, _replace);
				pos = stringContents.find(_find, pos);
			}
			//copy string into outfile
			outfile << stringContents;
			outfile.close();
		}
		else
			std::cout << "Outfile error" << std::endl;
		infile.close();
	}
	else
		std::cout << "Infile error" << std::endl;
}

/* NOTE:
Overloading means that a function can take several different types of parameters
An operator can perform different functions depending on the context
member initializer list*/

