#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
	std::string	m_name;
	Weapon&		m_weapon;
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void	attack() const;
};

#endif

/* NOTES:
we are including a ref to weapon in constructor, because the object must have been precreated
Otherwise, HumanA constructor tries to call default constructor of weapon which does not exist
ALSO, ORDER OF INITIALIZATION IN CONSTRUCTORS MATTER
if m_name comes first, it also must be initialized first in constructor
*/