#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string m_name;
public:
	Zombie();
	~Zombie();
	void	setName(std::string name);
	void	announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif

//NOTE: when using a copy constructor, a temp obj is created. temp obj is used to create new obj. temp obj is destroyed
//use a setter instead