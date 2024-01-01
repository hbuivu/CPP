#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class AMateria;
typedef struct s_AMateriaList AMateriaList; //when using typedef, forward declaration must include typedef!!

class ICharacter
{
public:
	virtual ~ICharacter(){}; //don't forget the {}!!! Since the destructor is not set to 0, the destructor needs to be defined somehow. Either 

	virtual const std::string&	getName() const = 0;
	virtual void				equip(AMateria* m) = 0;
	virtual void				unequip(int idx) = 0;
	virtual void				use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
private:
	std::string				_name;
	AMateria*				_materia[4];
	static AMateriaList*	_droppedMateria; //static members should typically be private
	static AMateriaList*	_lastDroppedMateria;
public:
	Character();
	Character(const std::string& name);
	Character(const Character& src);
	~Character();

	Character&	operator=(const Character& src);

	const std::string&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				dropMateria(int idx);
	void				use(int idx, ICharacter& target);
	void				clearMateria();
	static void			clearDroppedMateria();
};

#endif