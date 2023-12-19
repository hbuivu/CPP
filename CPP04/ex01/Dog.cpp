#include "Polymorphism.hpp"

Dog::Dog()
	:	Animal(),
		_brain(new Brain[100])
{
	_type = "Dog";
	std::cout << "<Dog> default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain[];
	std::cout << "<Dog> destructor called" << std::endl;
}

Dog::Dog(const Dog& src)
	:	Animal(cpy),
		_type(cpy._type),
		_brain(new Brain[100])
{
	for (int i = 0; i < 100; i++)
		std::strcpy(this->_brain[i], src._brain[i]);
	std::cout << "<Dog> copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& src)
{
	if (this != &og)
		this->_type = og.type;
	std::cout << "<Dog> copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
