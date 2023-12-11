#ifndef SED_HPP
# define SED_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

class Sed
{
private:
	std::string	m_infile;
	std::string m_outfile;
	std::string	m_find;
	std::string	m_replace;
public:
	Sed(std::string infile, std::string find, std::string replace);
	~Sed();
	void	replace();
};

#endif