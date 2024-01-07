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

Sed::Sed()
{
}

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
	//open file for reading
	std::ifstream infile(_infile); //ifstream opens up a file for input
	if (infile.is_open())
	{
		//if infile is valid open outfile to be written into
		 	std::ofstream outfile(_outfile); //ofstream opens up a file for output
		if (outfile.is_open()) //check that outfile was opened properly
		{
			//if s1 is the same as s2, or infile exists but is empty, copy files and exit
			if (_find.compare(_replace) == 0 || 
				infile.peek() == std::ifstream::traits_type::eof())
			{
				outfile << infile.rdbuf(); // send contents of infile to outfile
				outfile.close();
				infile.close();
				return ;
			}
			//stream contents of infile into file - another method would be to getline the whole file into a string
			std::ostringstream contents; //ostringstream is an output stream that you can write to
			contents << infile.rdbuf();
			std::string stringContents = contents.str(); //convert output stream to a string
			size_t	pos = stringContents.find(_find);
			while (pos != std::string::npos) //std::string::npos = last index of the string
			{
				stringContents.erase(pos, _find.length());
				stringContents.insert(pos, _replace);
				pos = stringContents.find(_find, pos + _replace.length()); // add length of replace bc we don't want to overlay the replaced string and get infinite lop ex: replace a with aba
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
member initializer list*
check if file is a directory -> std::filesystem::is_directory() - C++11

istream& getline(istream& is, string& str, char delim)
is - input stream
str - str to hold contents
delimiter - where should the function stop reading
*/

