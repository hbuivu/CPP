#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter();

	virtual const std::string&	getName() const = 0;
	virtual void				equip(AMateria* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
protected:
	std::string	_name;
	AMateria	*_materia;
public:
	Character();
	Character(const std::string& name);
	Character(const Character& src);
	~Character();

	Character&	operator=(const Character& src);

	const std::string&	getName() const override;
	void				equip(AMateria* m) override;
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif