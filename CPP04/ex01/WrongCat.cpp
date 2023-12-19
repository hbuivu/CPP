#include "Polymorphism.hpp"

WrongCat::WrongCat()
	:	WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "<WrongCat> default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "<WrongCat> destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy)
	:	WrongAnimal(cpy)
{
	this->_type = cpy._type;
	std::cout << "<WrongCat> copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& og)
{
	if (this != &og)
		this->_type = og._type;
	std::cout << "<WrongCat> copy assignment operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongMeow" << std::endl;
}
