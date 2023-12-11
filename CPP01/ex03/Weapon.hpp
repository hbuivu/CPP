#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
private:
	std::string m_type;
public:
	Weapon(std::string type);
	~Weapon();
	const std::string&	getType();
	void				setType(std::string newType);
};

#endif

/* NOTES: 
Always include semicolon after class!!!!
look up when const comes before and after a type
& comes at the end of type if its a ref*/