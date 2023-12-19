#include "Polymorphism.hpp"

Dog::Dog()
	:	Animal()
{
	_type = "Dog";
	std::cout << "<Dog> default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "<Dog> destructor called" << std::endl;
}

Dog::Dog(const Dog& cpy)
	:	Animal(cpy)
{
	this->_type = cpy._type;
	std::cout << "<Dog> copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& og)
{
	if (this != &og)
		this->_type = og._type;
	std::cout << "<Dog> copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
