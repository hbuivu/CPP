#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string		_type;
public:
	AMateria();
	AMateria(const std::string& type);
	AMateria(const AMateria& src);
	virtual ~AMateria();
	AMateria&	operator=(const AMateria& src);

	const std::string&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& src);
	~Ice();

	Ice&	operator=(const Ice& src); //WHILE ASSIGNING A MATERIA TO ANOTHER COPYING THE TYPE DOES NOT MAKE SENSE???

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& src);
	~Cure();

	Cure&	operator=(const Cure& src);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

typedef struct s_AMateriaList
{
	AMateria*				materia;
	struct s_AMateriaList*	next;
}	AMateriaList;

#endif

/* NOTES:
const std::string & type and std::string const & type is the same thing
for virtual functions, in C++11 and later, we can use the override keyword
and use covariant return types for virtual functions (so instead of AMateria*, use Cure*)
In C++98 this is not possible and we must use exact matching function signature
I denotes an interface - a  pure abstract class
*/