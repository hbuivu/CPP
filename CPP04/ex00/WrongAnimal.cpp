#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
	:	_type("wrong animal")
{
	std::cout << "<WrongAnimal> default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "<WrongAnimal> destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	this->_type = src._type;
	std::cout << "<WrongAnimal> copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "<WrongAnimal> copy assignment operator called" << std::endl;
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "A wrong animal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}
