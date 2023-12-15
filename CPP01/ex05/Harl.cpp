#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "<DEBUG>" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "<INFO>" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "<WARNING>" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "<ERROR>" << std::endl;
}

void	Harl::complain(std::string level)
{
	Harl::funcPtr funcArray[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while(i < 4)
	{
		if (levelArray[i].compare(level) == 0)
			break ;
		i++;
	}
	if (i == 4)
		std::cout << "Invalid complaint" << std::endl;
	else
		(this->*funcArray[i])();

}