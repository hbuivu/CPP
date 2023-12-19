#include "Polymorphism.hpp"

Animal::Animal()
	:	_type("animal")
{
	std::cout << "<Animal> default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "<Animal> destructor called" << std::endl;
}

Animal::Animal(const Animal& cpy)
{
	this->_type = cpy._type;
	std::cout << "<Animal> copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& og)
{
	if (this != &og)
		this->_type = og._type;
	std::cout << "<Animal> copy assignment operator called" << std::endl;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "An animal sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (_type);
}
