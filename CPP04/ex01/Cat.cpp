#include "Polymorphism.hpp"

Cat::Cat()
	:	Animal(),
		_brain(new Brain[100])
{
	_type = "Cat";
	std::cout << "<Cat> default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain[];
	std::cout << "<Cat> destructor called" << std::endl;
}

Cat::Cat(const Cat& cpy)
	:	Animal(cpy)
{
	this->_type = cpy._type;
	std::cout << "<Cat> copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& og)
{
	if (this != &og)
		this->_type = og._type;
	std::cout << "<Cat> copy assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
