#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>

class ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitPts;
	unsigned int	_energyPts;
	unsigned int	_attackDmg;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& cpy);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& og);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif