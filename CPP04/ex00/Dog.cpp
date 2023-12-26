#include "Dog.hpp"

Dog::Dog()
	:	Animal()
{
	_type = "Dog";
	std::cout << "<Dog> default constructor called" << std::endl;
}

Dog::Dog(const Dog& src)
	:	Animal(src)
{
	this->_type = src._type;
	std::cout << "<Dog> copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "<Dog> destructor called" << std::endl;
}


Dog&	Dog::operator=(const Dog& src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "<Dog> copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const //virtual only has to be declared when creating class
{
	std::cout << "Woof" << std::endl;
}
