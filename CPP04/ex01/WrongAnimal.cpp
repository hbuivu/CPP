#include "WrongPolymorphism.hpp"


WrongAnimal::WrongAnimal()
	:	_type("animal")
{
	std::cout << "<WrongAnimal> default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "<WrongAnimal> destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
	this->_type = cpy._type;
	std::cout << "<WrongAnimal> copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& og)
{
	if (this != &og)
		this->_type = og._type;
	std::cout << "<WrongAnimal> copy assignment operator called" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "A wrong animal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (_type);
}
