#include "HarlFilter.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\n";
	std::cout << "We're going to debug something now\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]\n";
	std::cout << "Please give me some info\n" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "[WARNING]\n";
	std::cout << "A bunch of warnings\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR\n";
	std::cout << "There's an error\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while(i < 4)
	{
		if (levelArray[i].compare(level) == 0)
			break ;
		i++;
	}
	switch(i)
	{
		case 0:
			error();
		case 1:
			warning();
		case 2:
			info();
		case 3:
			debug();
			break ;
		default:
			std::cout << "[Probably complaining about insignificant problems]" << std::endl;
	}
}

/* NOTES:
Switch only takes int (or char int) as parameter.
This is because switch uses jump tables, which only takes integer values
Bc switch uses look up tables, it is faster than else-if statements that have to go through all previous if statements
All case values must be known at compile time
Fallthrough - if a case is found, that case as well as everything below it will be executed until break statement*/