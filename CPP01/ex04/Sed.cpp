/* NOTE:
Overloading means that a function can take several different types of parameters
An operator can perform different functions depending on the context
member initializer list*/

#include "Sed.hpp"

Sed::Sed(std::string infile, std::string find, std::string replace) 
	:	m_infile(infile),
		m_find(find),
		m_replace(replace)
{
	this->m_outfile = this->m_infile + ".replace";
}

Sed::~Sed()
{
}

void	Sed::replace()
{
	//open file for reading
	std::ifstream	infile(this->m_infile.c_str());
	if (infile.is_open())
	{
		//if infile is valid open outfile to be written into
		std::ofstream	outfile(this->m_outfile.c_str());
		if (outfile.is_open())
		{
			//if s1 is the same as s2, copy files and exit
			if (this->m_find.compare(this->m_replace) == 0 || 
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
			size_t	pos = stringContents.find(this->m_find);
			while (pos != std::string::npos)
			{
				stringContents.erase(pos, this->m_find.length());
				stringContents.insert(pos, this->m_replace);
				pos = stringContents.find(this->m_find, pos);
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

