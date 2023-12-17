#include "Polymorphism.hpp"

Animal::Animal()
	:	_type("animal")
{
}

Animal::~Animal()
{
}

void	Animal::makeSound() const
{
	std::cout << "neigh\n";
}

std::string	Animal::getType() const
{
	return (_type);
}