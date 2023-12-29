#include "AMateria.hpp"

AMateria::AMateria()
	:	_type("AMateria")
{
}

AMateria::AMateria(const std::string& type)
	:	_type(type)
{
}

AMateria::AMateria(const AMateria& src)
	:	_type(src._type)
{
}

AMateria::~AMateria()
{
}

AMateria&	AMateria::operator=(const AMateria& src)
{
	this->_type = src._type;
}

const std::string&	AMateria::getType() const
{
	return(_type);
}

void	use(ICharacter& target)
{
	std::cout << "raw material AMateria cannot be used" << std::endl;
}

/****************************************/

Ice::Ice()
	:	AMateria()
{
	_type = "ice";
}

Ice::Ice(const Ice& src)
	:	AMateria(src)
{
}

Ice::~Ice()
{
}

Ice&	Ice::operator=(const Ice& src)
{
	this->_type = src._type;
}

void	use(ICharacter& target)
{
	std::cout << "*shoot an ice bolt at " << target.getName() << "*" << std::endl;
}

/****************************************/

Cure::Cure()
	:	AMateria()
{
	_type = "cure";
}

Cure::Cure(const Cure& src)
	:	AMateria(src)
{
}

Cure::~Cure()
{
}

Cure&	Cure::operator=(const Cure& src)
{
	this->_type = src._type;
}

void	use(ICharacter& target)
{
	std::cout << "*heals " << target.getName() << "'s wounds*" << std::endl;
	//delete from 
}

