#include "WrongCat.hpp"

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

WrongCat::WrongCat(const WrongCat& src)
	:	WrongAnimal(src)
{
	this->_type = src._type;
	std::cout << "<WrongCat> copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "<WrongCat> copy assignment operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongMeow" << std::endl;
}
